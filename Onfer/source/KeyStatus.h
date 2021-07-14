#ifndef ONFER_KEY_STATUS_H
#define ONFER_KEY_STATUS_H

namespace Onfer {

	class KeyStatus {
	private:
		bool m_KeyPress;
		bool m_KeyUpdate;
	public:
		KeyStatus();
		~KeyStatus();
		bool isKeyPress() const;
		bool isKeyUpdate() const;
		void setKeyPress(bool keyPress);
		void setKeyUpdate(bool keyUpdate);
	};

}

#endif