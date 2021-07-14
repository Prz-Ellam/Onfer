#ifndef ONFER_WINDOW_H
#define ONFER_WINDOW_H

#include <Windows.h>
#include <string>
#include <functional>
#include "ShowWindowMode.h"
#include "KeyEvents.h"
#include "MouseMoveEvent.h"
#include "WindowResizeEvent.h"
#include "WindowCloseEvent.h"
#include "WindowEvents.h"
#include "WindowMoveEvent.h"
#include "../utils/Log.h"
#include "../Renderer/OpenGL/OpenGLContext.h"
#include "../Renderer/Context.h"

namespace Onfer {

	using WindowResizeEventFn = std::function<void(WindowResizeEvent)>;
	using WindowCloseEventFn = std::function<void(WindowCloseEvent)>;
	using WindowMoveEventFn = std::function<void(WindowMoveEvent)>;
	using KeyEventsFn = std::function<void(KeyEvents)>;

	class Window {
	private:
		HWND hWnd;
		Context* m_Context;
		uint32_t m_Width, m_Height;
		std::string m_Title;

		static WindowResizeEventFn windowResizeEventCallback;
		static WindowCloseEventFn windowCloseEventCallback;
		static WindowMoveEventFn windowMoveEventCallback;
		static KeyEventsFn keyEventsCallback;

		bool registerWindowClass();
		bool init();
		void pollEvents();
		void close();
	public:
		Window(uint32_t width, uint32_t height, const std::string& title);
		Window();
		virtual ~Window();

		void show(ShowWindowMode sw);
		void update();

		uint32_t getWidth() const;
		uint32_t getHeight() const;

		void setWindowResizeEventCallback(WindowResizeEventFn callback);
		void setWindowMoveEventCallback(WindowMoveEventFn callback);
		void setWindowCloseEventCallback(WindowCloseEventFn callback);
		void setKeyEventsCallback(KeyEventsFn callback);

		static LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	};

}

#endif