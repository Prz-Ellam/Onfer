#ifndef ONFER_APPLICATION_H
#define ONFER_APPLICATION_H

#include "Window.h"
#include "WindowResizeEvent.h"
#include "WindowCloseEvent.h"

namespace Onfer {

	class Application {
	private:
		Window* m_Window;
		bool m_Running;
	public:
		Application();
		~Application();
		void onEvent();
		void run();

		void windowResizeEvent(WindowResizeEvent e);
		void windowCloseEvent(WindowCloseEvent e);
		void keyEvents(KeyEvents e);
	};

}

#endif