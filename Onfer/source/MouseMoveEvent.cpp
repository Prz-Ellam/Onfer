#include "MouseMoveEvent.h"
#include <sstream>

namespace Onfer {

	MouseMoveEvent::MouseMoveEvent() : m_X(0.0), m_Y(0.0) {}
	MouseMoveEvent::~MouseMoveEvent() {}

	void MouseMoveEvent::updateMousePosition(double x, double y) {

		m_X = x;
		m_Y = y;

	}

	double MouseMoveEvent::getXPosition() {
	
		return m_X;

	}

	double MouseMoveEvent::getYPosition() {
	
		return m_Y;

	}

	std::string MouseMoveEvent::toString() {
		
		std::stringstream ss;
		ss << "(" << m_X << ", " << m_Y << ")";
		return ss.str();

	}

}