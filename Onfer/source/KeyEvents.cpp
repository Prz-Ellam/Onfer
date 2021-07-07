#include "KeyEvents.h"

namespace Onfer {

	KeyEvents::KeyEvents() {

	}

	KeyEvents::~KeyEvents() {

	}

	void KeyEvents::disableAllKeys() {

		for (int i = 0; i < count; i++) {

			keys[(int)i].setKeyPress(false);
			keys[(int)i].setKeyUpdate(false);

		}

	}

	void KeyEvents::updateKey(KeyCode keyCode, bool status) {

		keys[(int)keyCode].setKeyPress(status);
		keys[(int)keyCode].setKeyUpdate(true);

	}

	KeyStatus KeyEvents::getKeyStatus(KeyCode keyCode) const {

		return keys[(int)keyCode];

	}

	bool KeyEvents::isKeyPressed(KeyCode keyCode) const {

		return keys[(int)keyCode].isKeyPress() && keys[(int)keyCode].isKeyUpdate();
	
	}

	bool KeyEvents::isKeyRelease(KeyCode keyCode) const {

		return !keys[(int)keyCode].isKeyPress() && keys[(int)keyCode].isKeyUpdate();

	}

	void KeyEvents::restart() {

		for (int i = 0; i < count; i++) {

			if (!keys[i].isKeyPress() && keys[i].isKeyUpdate())
				lastKey = (KeyCode)i;

			keys[i].setKeyUpdate(false);

		}

	}

	KeyCode KeyEvents::getLastKey() const {

		return lastKey;

	}

}