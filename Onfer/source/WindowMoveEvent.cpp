#include "WindowMoveEvent.h"
#include <sstream>

namespace Onfer {

	WindowMoveEvent::WindowMoveEvent() : m_X(0), m_Y(0) {

	}

	WindowMoveEvent::WindowMoveEvent(uint32_t x, uint32_t y) : m_X(x), m_Y(y) {

	}

	void WindowMoveEvent::updateWindowSize(uint32_t x, uint32_t y) {

		m_X = x;
		m_Y = y;

	}

	std::string WindowMoveEvent::toString() {

		std::stringstream ss;
		ss << "WindowMoveEvent: (" << m_X << ", " << m_Y << ")";
		return ss.str();

	}

	uint32_t WindowMoveEvent::getX() const {

		return m_X;

	}

	uint32_t WindowMoveEvent::getY() const {

		return m_Y;

	}



}