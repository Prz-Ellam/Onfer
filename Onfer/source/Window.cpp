#include "Window.h"

namespace Onfer {

	WindowResizeEventFn Window::windowResizeEventCallback = [](WindowResizeEvent e) {};
	WindowCloseEventFn Window::windowCloseEventCallback = [](WindowCloseEvent e) {};
	WindowMoveEventFn Window::windowMoveEventCallback = [](WindowMoveEvent e) {};
	KeyEventsFn Window::keyEventsCallback = [](KeyEvents e) {};

	Window::Window(uint32_t width, uint32_t height, const std::string& title) : m_Width(width), m_Height(height), m_Title(title) {

		if (!init())
			Log::error("No se pudo iniciar la ventana");
		m_Context = new OpenGLContext(hWnd);
		m_Context->makeContextCurrent();

	}

	Window::Window() : m_Width(1280), m_Height(720), m_Title("Onfer Engine!") {

		if (!init())
			Log::error("No se pudo iniciar la ventana");
		m_Context = new OpenGLContext(hWnd);
		m_Context->makeContextCurrent();

	}

	Window::~Window() {

		delete m_Context;

	}

	bool Window::registerWindowClass() {

		WNDCLASSEX wndClass = {};
		wndClass.cbSize = sizeof(WNDCLASSEX);
		wndClass.style = CS_HREDRAW | CS_VREDRAW;
		wndClass.lpfnWndProc = WindowProcedure;
		wndClass.hInstance = GetModuleHandle(nullptr);
		wndClass.hIcon = LoadIcon(wndClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
		wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wndClass.hbrBackground = (HBRUSH)0;
		wndClass.lpszClassName = "GameWindowClass";
		wndClass.hIconSm = LoadIcon(wndClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

		return RegisterClassEx(&wndClass);

	}

	bool Window::init() {

		if (!registerWindowClass()) {
			Log::error("No se pudo registrar la ventana");
			return false;
		}

		hWnd = CreateWindowEx(NULL,
			"GameWindowClass",
			m_Title.c_str(),
			WS_OVERLAPPEDWINDOW,
			0,
			0,
			m_Width,
			m_Height,
			nullptr,
			nullptr,
			GetModuleHandle(nullptr),
			nullptr);

		return hWnd;

	}

	void Window::show(ShowWindowMode sw) {

		ShowWindow(hWnd, static_cast<int>(sw));

	}

	void Window::update() {

		pollEvents();
		m_Context->swapBuffers();

	}

	void Window::pollEvents() {

		MSG msg = {};
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}

	void Window::close() {

		DestroyWindow(hWnd);

	}

	uint32_t Window::getWidth() const {

		return m_Width;

	}

	uint32_t Window::getHeight() const {

		return m_Height;

	}

	void Window::setWindowResizeEventCallback(WindowResizeEventFn callback) {

		windowResizeEventCallback = callback;

	}

	void Window::setWindowMoveEventCallback(WindowMoveEventFn callback) {

		windowMoveEventCallback = callback;

	}

	void Window::setWindowCloseEventCallback(WindowCloseEventFn callback) {

		windowCloseEventCallback = callback;

	}

	void Window::setKeyEventsCallback(KeyEventsFn callback) {

		keyEventsCallback = callback;

	}

	LRESULT CALLBACK Window::WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

		switch (uMsg) {
			/*case WM_KEYUP:
			case WM_KEYDOWN: {

				bool status = (uMsg == WM_KEYDOWN) ? 1 : 0;

				static KeyEvents e;
				e.updateKey((KeyCode)wParam, status);

				keyEventsCallback(e);
				break;
			}*/
			case WM_SIZE:
				windowResizeEventCallback(WindowResizeEvent(LOWORD(lParam), HIWORD(lParam)));
				break;
			case WM_MOVE:
				windowMoveEventCallback(WindowMoveEvent(LOWORD(lParam), HIWORD(lParam)));
				break;
			case WM_DESTROY:
				windowCloseEventCallback(WindowCloseEvent());
				break;
		}

		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

}