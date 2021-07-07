#ifndef ONFER_WINDOW_RESIZE_EVENT_H
#define ONFER_WINDOW_RESIZE_EVENT_H

#include <string>

namespace Onfer {

	class WindowResizeEvent {
	private:
		uint32_t m_Width, m_Height;
	public:
		WindowResizeEvent();
		WindowResizeEvent(uint32_t width, uint32_t height);

		void updateWindowSize(uint32_t width, uint32_t height);
		std::string toString();

		uint32_t getWidth() const;
		uint32_t getHeight() const;
	};

}

#endif