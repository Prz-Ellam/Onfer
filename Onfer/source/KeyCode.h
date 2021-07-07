#ifndef KEY_CODE_H
#define KEY_CODE_H

namespace Onfer {

	enum class KeyCode {

		LeftButton = 1, RightButton = 2, MiddleButton = 4,
		X1Button = 5, X2Button = 6,

		KeyBackSpace = 8, KeyTab = 9, KeyClear = 12, KeyEnter = 13,
		KeyShift = 16, KeyControl = 17, KeyEscape = 27, KeySpace = 32,

		KeyLeft = 37, KeyUp = 38, KeyRight = 39, KeyDown = 40,

		// 0-9
		Key0 = 48, Key1 = 49, Key2 = 50, Key3 = 51, Key4 = 52,
		Key5 = 53, Key6 = 54, Key7 = 55, Key8 = 56, Key9 = 57,

		// A-Z
		KeyA = 65, KeyB = 66, KeyC = 67, KeyD = 68, KeyE = 69,
		KeyF = 70, KeyG = 71, KeyH = 72, KeyI = 73, KeyJ = 74,
		KeyK = 75, KeyL = 76, KeyM = 77, KeyN = 78, KeyO = 79,
		KeyP = 80, KeyQ = 81, KeyR = 82, KeyS = 83, KeyT = 84,
		KeyU = 85, KeyV = 86, KeyW = 87, KeyX = 88, KeyY = 89,
		KeyZ = 90,

		// Numpads
		KeyNumpad0 = 96, KeyNumpad1 = 97, KeyNumpad2 = 98, KeyNumpad3 = 99,
		KeyNumpad4 = 100, KeyNumpad5 = 101, KeyNumpad6 = 102, KeyNumpad7 = 103,
		KeyNumpad8 = 104, KeyNumpad9 = 105,

		// Function Keys
		KeyF1 = 112, KeyF2 = 113, KeyF3 = 114, KeyF4 = 115, KeyF5 = 116,
		KeyF6 = 117, KeyF7 = 118, KeyF8 = 119, KeyF9 = 120, KeyF10 = 121,
		KeyF11 = 122, KeyF12 = 123, KeyF13 = 124, KeyF14 = 125, KeyF15 = 126,
		KeyF16 = 127, KeyF17 = 128, KeyF18 = 129, KeyF19 = 130, KeyF20 = 131,
		KeyF21 = 132, KeyF22 = 133, KeyF23 = 134, KeyF24 = 135
	};

	unsigned const int count = 136;

}

#endif