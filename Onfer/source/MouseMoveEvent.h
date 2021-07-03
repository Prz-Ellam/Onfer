#ifndef MOUSE_MOVE_H
#define MOUSE_MOVE_H

#include <string>

namespace Onfer {

	class MouseMoveEvent {
	private:
		double m_X, m_Y;
	public:
		MouseMoveEvent();
		~MouseMoveEvent();

		void updateMousePosition(double x, double y);
		double getXPosition();
		double getYPosition();

		std::string toString();

	};

}

#endif