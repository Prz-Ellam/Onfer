#ifndef MOUSE_MOVE_H
#define MOUSE_MOVE_H

#include <string>

namespace Onfer {

	class MouseMoveEvent {
	private:
		double m_X, m_Y;
	public:
		MouseMoveEvent();
		MouseMoveEvent(double x, double y);
		~MouseMoveEvent();

		// Manager Event methods
		void updateMousePosition(double x, double y);
		std::string toString();

		// Client methods
		double getX() const;
		double getY() const;

	};

}

#endif