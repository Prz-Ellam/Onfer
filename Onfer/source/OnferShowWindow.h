#ifndef _SHOW_WINDOW_H
#define _SHOW_WINDOW_H

namespace Onfer {

	enum class OnferShowWindow {
		Hide = 0,
		ShowNormal,
		Normal = ShowNormal,
		ShowMinimized,
		Maximized,
		ShowMaximized = Maximized,
		NoActivate,
		Show,
		Minimized,
		ShowMinNoActive,
		ShowNa,
		Restore,
		ShowDefault,
		ForceMinimized
	};

}

#endif