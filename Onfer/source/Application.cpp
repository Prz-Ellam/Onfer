#include "Application.h"
#include <chrono>

namespace Onfer {

	Application::Application() : m_Running(true) {

		m_Window = new Window();
		onEvent();
		m_Window->show(ShowWindowMode::ShowDefault);

	}

	Application::~Application() {

		m_Window->close();
		delete m_Window;

	}

	void Application::onEvent() {
	
		m_Window->windowResizeEventDispatcher(std::bind(&Application::windowResizeEvent, this, std::placeholders::_1));
		m_Window->windowCloseEventDispatcher(std::bind(&Application::windowCloseEvent, this, std::placeholders::_1));
		m_Window->keyEventsDispatcher(std::bind(&Application::keyEvents, this, std::placeholders::_1));

	}

	void Application::run() {

		auto start = std::chrono::high_resolution_clock::now();
		while (m_Running) {
			m_Window->update();
			auto end = std::chrono::high_resolution_clock::now();

			std::chrono::duration<double> diff = end - start;
			//printf("%4f s \n", diff.count() * 1000.0);
			start = end;
		}

	}

	void Application::windowResizeEvent(WindowResizeEvent e) {

		printf("Window resize event");
		printf(e.toString().c_str());
		printf("\n");

	}

	void Application::windowCloseEvent(WindowCloseEvent e) {

		m_Running = false;

	}

	void Application::keyEvents(KeyEvents e) {

		if (e.isKeyPressed(KeyCode::KeyW)) {
			printf("Key W is pressed\n");
		}
		if (e.isKeyPressed(KeyCode::KeyA)) {
			printf("Key A is pressed\n");
		}
		//if (e.getLastKey() == KeyCode::KeyF) {
			//printf("F is the last key pressed\n");
		//}

	}

}