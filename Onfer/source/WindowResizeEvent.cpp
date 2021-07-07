#include "WindowResizeEvent.h"
#include <sstream>

namespace Onfer {

	WindowResizeEvent::WindowResizeEvent() : m_Width(0), m_Height(0) {
	
	}


	WindowResizeEvent::WindowResizeEvent(uint32_t width, uint32_t height) : m_Width(width), m_Height(height) {

	}

	void WindowResizeEvent::updateWindowSize(uint32_t width, uint32_t height) {

		m_Width = width;
		m_Height = height;

	}

	std::string WindowResizeEvent::toString() {

		std::stringstream ss;
		ss << "WindowResizeEvent: (" << m_Width << ", " << m_Height << ")";
		return ss.str();

	}

	uint32_t WindowResizeEvent::getWidth() const {
	
		return m_Width;
	
	}

	uint32_t WindowResizeEvent::getHeight() const {

		return m_Height;

	}

}