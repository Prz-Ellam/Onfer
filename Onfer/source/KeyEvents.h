#ifndef ONFER_KEY_EVENTS_H
#define ONFER_KEY_EVENTS_H

#include "KeyStatus.h"
#include "KeyCode.h"

#define IsKeyPressed(Key) GetKeyState((int)Key) & 1 << 16
#define IsKeyRelease(Key) !GetKeyState((int)Key)

namespace Onfer {

	class KeyEvents {
	private:
		KeyStatus keys[count];
		KeyCode lastKey;
	public:
		KeyEvents();
		virtual ~KeyEvents();

		// Manager Event methods
		void disableAllKeys();
		void updateKey(KeyCode keyCode, bool status);
		void restart();

		// Client methods
		KeyStatus getKeyStatus(KeyCode keyCode) const;
		bool isKeyPressed(KeyCode keyCode) const;
		bool isKeyRelease(KeyCode keyCode) const;
		KeyCode getLastKey() const;
	};

}

#endif