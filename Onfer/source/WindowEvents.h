#ifndef ONFER_WINDOW_EVENTS_H
#define ONFER_WINDOW_EVENTS_H

#include <stdint.h>

namespace Onfer {

	class WindowEvents {
	private:
		uint32_t m_Width, m_Height;
		uint32_t m_X, m_Y;
		bool m_Minimized;
		bool m_Close;
	public:
		WindowEvents();
		virtual ~WindowEvents();

		uint32_t getWidth() const;
		uint32_t getHeight() const;
		uint32_t getX() const;
		uint32_t getY() const;
		bool isMinimized() const;

		void setWidth(uint32_t width);
		void setHeight(uint32_t height);
		void setX(uint32_t x);
		void setY(uint32_t y);

		void setSize(uint32_t width, uint32_t height);
		void setPosition(uint32_t x, uint32_t y);
		void setMinimized(bool minimized);

	};

}

#endif