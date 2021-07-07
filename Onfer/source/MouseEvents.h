#ifndef ONFER_MOUSE_EVENTS_H
#define ONFER_MOUSE_EVENTS_H

#include "KeyStatus.h"
#include "KeyCode.h"

namespace Onfer {

	class MouseEvents {
	private:
		KeyCode m_MouseKeys[5];
		double m_X, m_Y;
	public:
		MouseEvents();
		virtual ~MouseEvents();

		void restart();
		bool isKeyPressed(KeyCode keyCode) const;
		bool isKeyRelease(KeyCode keyCode) const;
	};

}

#endif