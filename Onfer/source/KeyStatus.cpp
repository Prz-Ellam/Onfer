#include "KeyStatus.h"

namespace Onfer {

	KeyStatus::KeyStatus() : m_KeyPress(false), m_KeyUpdate(false) {
	
	}

	KeyStatus::~KeyStatus() {
	
	}

	bool KeyStatus::isKeyPress() {

		return m_KeyPress;

	}

	bool KeyStatus::isKeyUpdate() {

		return m_KeyUpdate;
	
	}

	void KeyStatus::setKeyPress(bool keyPress) {

		m_KeyPress = keyPress;
	
	}

	void KeyStatus::setKeyUpdate(bool keyUpdate) {

		m_KeyUpdate = keyUpdate;
	
	}


}