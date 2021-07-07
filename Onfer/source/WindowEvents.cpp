#include "WindowEvents.h"

namespace Onfer {

	WindowEvents::WindowEvents() : m_Width(0), m_Height(0), m_X(0), m_Y(0), m_Minimized(0), m_Close(0) {
	
	}

	WindowEvents::~WindowEvents() {
	
	}

	uint32_t WindowEvents::getWidth() const {

		return m_Width;

	}

	uint32_t WindowEvents::getHeight() const {

		return m_Height;

	}

	uint32_t WindowEvents::getX() const {

		return m_X;

	}

	uint32_t WindowEvents::getY() const {

		return m_Y;

	}

	bool WindowEvents::isMinimized() const {

		return m_Minimized;

	}

	void WindowEvents::setWidth(uint32_t width) {
	
		m_Width = width;

	}

	void WindowEvents::setHeight(uint32_t height) {

		m_Height = height;
	
	}

	void WindowEvents::setX(uint32_t x) {

		m_X = x;
	
	}

	void WindowEvents::setY(uint32_t y) {

		m_Y = y;
	
	}

	void WindowEvents::setSize(uint32_t width, uint32_t height) {

		m_Width = width;
		m_Height = height;
	
	}

	void WindowEvents::setPosition(uint32_t x, uint32_t y) {

		m_X = x;
		m_Y = y;
	
	}

	void WindowEvents::setMinimized(bool minimized) {

		m_Minimized = minimized;
	
	}

}