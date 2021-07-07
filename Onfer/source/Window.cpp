#include "Window.h"
#include <stdio.h>

namespace Onfer {

	std::function<void(WindowResizeEvent)> Window::windowResizeEventHandler = nullptr;
	std::function<void(WindowCloseEvent)> Window::windowCloseEventHandler = nullptr;
	std::function<void(KeyEvents)> Window::keyEventsHandler = nullptr;
	KeyEvents Window::keys = KeyEvents();

	WindowProperties::WindowProperties(uint32_t _width, uint32_t _height, const std::string& _title) {
		width = _width;
		height = _height;
		title = _title;
	}

	WindowProperties::WindowProperties() {

	}

	Window::Window(WindowProperties _properties) : properties(_properties) {

		if (!init())
			printf("ERROR\n");

	}

	Window::~Window() {

	}

	bool Window::init() {

		if (!registerWindow()) {
			printf("ERROR");
			return false;
		}

		hWnd = CreateWindowEx(NULL,
			"OnferEngine",
			properties.title.c_str(),
			WS_OVERLAPPEDWINDOW,
			200,
			200,
			properties.width,
			properties.height,
			NULL,
			NULL,
			GetModuleHandle(nullptr),
			NULL
		);

		return hWnd;

	}

	void Window::show(ShowWindowMode sw) {

		ShowWindow(hWnd, static_cast<int>(sw));

	}

	bool Window::registerWindow() {

		WNDCLASSEX wndClass = {};
		wndClass.cbSize = sizeof(WNDCLASSEX);
		wndClass.style = CS_HREDRAW | CS_VREDRAW;
		wndClass.lpfnWndProc = WindowProcedure;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hInstance = GetModuleHandle(nullptr);
		wndClass.hIcon = LoadIcon(wndClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
		wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wndClass.lpszMenuName = nullptr;
		wndClass.lpszClassName = "OnferEngine";
		wndClass.hIconSm = LoadIcon(wndClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

		return RegisterClassEx(&wndClass);

	}

	void Window::update() {

		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			keys.restart();
			//printf("%d\n", msg.message);


		}
		else {
			// Logic here

		}

	}

	void Window::close() {

		DestroyWindow(hWnd);

	}

	unsigned int Window::getWidth() const {

		return properties.width;

	}

	unsigned int Window::getHeight() const {

		return properties.height;

	}

	void Window::windowResizeEventDispatcher(std::function<void(WindowResizeEvent)> handler) {

		windowResizeEventHandler = handler;

	}

	void Window::windowCloseEventDispatcher(std::function<void(WindowCloseEvent)> handler) {

		windowCloseEventHandler = handler;

	}

	void Window::keyEventsDispatcher(std::function<void(KeyEvents)> handler) {

		keyEventsHandler = handler;

	}

	LRESULT CALLBACK Window::WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

		switch (uMsg) {
			case WM_SIZE: {

				WindowResizeEvent e = WindowResizeEvent(LOWORD(lParam), HIWORD(lParam));
				windowResizeEventHandler(e);

				break;
			}
			case WM_KEYUP:
			case WM_KEYDOWN: {

				bool isPressed = (uMsg == WM_KEYDOWN);

				KeyCode code = (KeyCode)wParam;
				switch (code) {
					case KeyCode::KeyW:
						keys.updateKey(KeyCode::KeyW, isPressed);
						break;
					case KeyCode::KeyA:
						keys.updateKey(KeyCode::KeyA, isPressed);
						break;
				}
				keyEventsHandler(keys);

				break;
			}
			case WM_MOVE: {

				break;
			}
			case WM_CLOSE: {
				
				WindowCloseEvent e = WindowCloseEvent();
				windowCloseEventHandler(e);

				break;
			}
			default:
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}

		return FALSE;
	}

}