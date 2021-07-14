#ifndef ONFER_WINDOW_MOVE_EVENT_H
#define ONFER_WINDOW_MOVE_EVENT_H

#include <stdint.h>
#include <string>

namespace Onfer {

	class WindowMoveEvent {
	private:
		uint32_t m_X, m_Y;
	public:
		WindowMoveEvent();
		WindowMoveEvent(uint32_t x, uint32_t y);

		void updateWindowSize(uint32_t x, uint32_t y);
		std::string toString();

		uint32_t getX() const;
		uint32_t getY() const;
	};

}

#endif