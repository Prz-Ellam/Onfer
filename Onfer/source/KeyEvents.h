#ifndef KEY_EVENTS_H
#define KEY_EVENTS_H

#include "KeyStatus.h"
#include "KeyCode.h"

namespace Onfer {

	class KeyEvents {
	private:
		KeyStatus keys[count];
		KeyCode lastKey;
	public:
		KeyEvents();
		~KeyEvents();
		void disableAllKeys();
		void updateKey(KeyCode keyCode, bool status);
		KeyStatus getKeyStatus(KeyCode keyCode);
		void restart();
		KeyCode getLastKey();
	};

}

#endif