#include "OnferWindow.h"
#include <stdio.h>

namespace Onfer {

	WindowProperties::WindowProperties(unsigned int _width, unsigned int _height, std::string _title) {
		width = _width;
		height = _height;
		title = _title;
	}

	WindowProperties::WindowProperties() {

	}

	OnferWindow::OnferWindow(WindowProperties _properties) : properties(_properties) {

		if (!registerWindow()) {
			printf("ERROR");
			return;
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

		if (!hWnd)
			printf("ERROR\n");

	}

	void OnferWindow::show(OnferShowWindow sw) {

		ShowWindow(hWnd, static_cast<int>(sw));

	}

	OnferWindow::~OnferWindow() {

		DestroyWindow(hWnd);

	}

	bool OnferWindow::registerWindow() {

		WNDCLASSEX wndClass = {};
		wndClass.cbSize = sizeof(WNDCLASSEX);
		wndClass.style = CS_HREDRAW | CS_VREDRAW;
		wndClass.lpfnWndProc = (WNDPROC)WindowProcedure;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hInstance = GetModuleHandle(nullptr);
		wndClass.hIcon = LoadIcon(wndClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
		wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wndClass.lpszMenuName = nullptr;
		wndClass.lpszClassName = "OnferEngine";
		wndClass.hIconSm = LoadIcon(wndClass.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

		if (RegisterClassEx(&wndClass)) {
			return true;
		}
		else {
			return false;
		}

	}

	void OnferWindow::run() {

		MSG msg = {};
		running = true;
		while (running) {
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);

				keyListener.restart();
				if (msg.message == WM_KEYDOWN || msg.message == WM_KEYUP) {
					bool isPressed = (msg.message == WM_KEYDOWN);
					keyListener.updateKey((KeyCode)msg.wParam, isPressed);
				}

				if (msg.message == WM_MOUSEMOVE) {

					mouseMoveListener.updateMousePosition(LOWORD(msg.lParam), HIWORD(msg.lParam));
					printf(mouseMoveListener.toString().c_str());
					printf("\n");

				}

				if (msg.message == WM_QUIT) {
					running = false;
				}
			}
			else {

			}
		}

	}

	bool OnferWindow::isRunning() {

		return running;

	}

	unsigned int OnferWindow::getWidth() {

		return properties.width;

	}

	unsigned int OnferWindow::getHeight() {

		return properties.height;

	}

	LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

		switch (uMsg) {
			case WM_CLOSE: {
				DestroyWindow(hWnd); 
				break;
			}
			case WM_DESTROY: {
				PostQuitMessage(0);
				break;
			}
			default:
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}

		return FALSE;
	}

}