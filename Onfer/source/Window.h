#ifndef ONF_WINDOW_H
#define ONF_WINDOW_H

#include <Windows.h>
#include <string>
#include <functional>
#include "ShowWindowMode.h"
#include "KeyEvents.h"
#include "MouseMoveEvent.h"
#include "WindowResizeEvent.h"
#include "WindowCloseEvent.h"
#include "WindowEvents.h"

namespace Onfer {

	struct WindowProperties {
		WindowProperties(uint32_t _width, uint32_t _height, const std::string& _title);
		WindowProperties();
		std::string title = "Onfer Engine!";
		uint32_t width = 1280, height = 720;
	};

	class Window {
	private:
		WindowProperties properties;
		HWND hWnd;
		MSG msg;
		static KeyEvents keys;
		static WindowEvents window;
		bool registerWindow();
		bool init();
		static std::function<void(WindowResizeEvent)> windowResizeEventHandler;
		static std::function<void(WindowCloseEvent)> windowCloseEventHandler;
		static std::function<void(KeyEvents)> keyEventsHandler;
	public:
		Window(WindowProperties properties = WindowProperties());
		virtual ~Window();
		void show(ShowWindowMode sw);
		void update();
		void close();
		unsigned int getWidth() const;
		unsigned int getHeight() const;

		void windowResizeEventDispatcher(std::function<void(WindowResizeEvent)> handler);
		void windowCloseEventDispatcher(std::function<void(WindowCloseEvent)> handler);
		void keyEventsDispatcher(std::function<void(KeyEvents)> handler);

		static LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	};

}

#endif