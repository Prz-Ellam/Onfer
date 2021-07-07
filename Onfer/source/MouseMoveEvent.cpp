#include "MouseMoveEvent.h"
#include <sstream>

namespace Onfer {

	MouseMoveEvent::MouseMoveEvent() : m_X(0.0), m_Y(0.0) {
	
	}

	MouseMoveEvent::MouseMoveEvent(double x, double y) : m_X(x), m_Y(y) {

	}

	MouseMoveEvent::~MouseMoveEvent() {}

	void MouseMoveEvent::updateMousePosition(double x, double y) {

		m_X = x;
		m_Y = y;

	}

	double MouseMoveEvent::getX() const {
	
		return m_X;

	}

	double MouseMoveEvent::getY() const {
	
		return m_Y;

	}

	std::string MouseMoveEvent::toString() {
		
		std::stringstream ss;
		ss << "MouseMove: (" << m_X << ", " << m_Y << ")";
		return ss.str();

	}

}