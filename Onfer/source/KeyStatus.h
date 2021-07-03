#ifndef KEY_STATUS_H
#define KEY_STATUS_H

namespace Onfer {

	class KeyStatus {
	private:
		bool m_KeyPress;
		bool m_KeyUpdate;
	public:
		KeyStatus();
		~KeyStatus();
		bool isKeyPress();
		bool isKeyUpdate();
		void setKeyPress(bool keyPress);
		void setKeyUpdate(bool keyUpdate);
	};

}

#endif