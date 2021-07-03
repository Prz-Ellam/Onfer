#ifndef ONF_WINDOW_H
#define ONF_WINDOW_H

#include <Windows.h>
#include <string>
#include "OnferShowWindow.h"
#include "KeyEvents.h"
#include "MouseMoveEvent.h"

namespace Onfer {

	struct WindowProperties {
		WindowProperties(unsigned int _width, unsigned int _height, std::string _title);
		WindowProperties();
		std::string title = "Onfer Engine!";
		unsigned int width = 1280, height = 720;
	};

	class OnferWindow {
	private:
		WindowProperties properties;
		KeyEvents keyListener;
		MouseMoveEvent mouseMoveListener;
		HWND hWnd;
		bool running;
		bool registerWindow();
	public:
		OnferWindow(WindowProperties properties = WindowProperties());
		void show(OnferShowWindow sw);
		virtual ~OnferWindow();
		void run();
		bool isRunning();
		unsigned int getWidth();
		unsigned int getHeight();
	};

	LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

}

#endif