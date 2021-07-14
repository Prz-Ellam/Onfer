#ifndef ONFER_OPENGL_CONTEXT_H
#define ONFER_OPENGL_CONTEXT_H

#include "../Context.h"
#include <Windows.h>

namespace Onfer {

	class OpenGLContext : public Context {
	public:
		OpenGLContext(HWND hWnd);
		virtual ~OpenGLContext();
		void makeContextCurrent() override;
		void swapBuffers() override;
	private:
		HDC hDC;
		HGLRC hGL;
		void defPixelFormat(HDC hDC);
	};

}


#endif