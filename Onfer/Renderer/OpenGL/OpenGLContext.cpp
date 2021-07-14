#include "OpenGLContext.h"

namespace Onfer {

	OpenGLContext::OpenGLContext(HWND hWnd) {

		HDC hDCAux = GetDC(hWnd);
		hDC = hDCAux;
		defPixelFormat(hDC);
		hGL = wglCreateContext(hDC);

	}

	OpenGLContext::~OpenGLContext() {

		wglMakeCurrent(nullptr, nullptr);
		wglDeleteContext(hGL);
	
	}

	void OpenGLContext::makeContextCurrent() {

		wglMakeCurrent(hDC, hGL);

	};

	void OpenGLContext::swapBuffers() {
	
		SwapBuffers(hDC);

	}

	void OpenGLContext::defPixelFormat(HDC hDC) {

		PIXELFORMATDESCRIPTOR pfd = {
			sizeof(PIXELFORMATDESCRIPTOR),    
			1,                   
			PFD_DRAW_TO_WINDOW | 
			PFD_SUPPORT_OPENGL | 
			PFD_DOUBLEBUFFER,    
			PFD_TYPE_RGBA,       
			24,                  
			0, 0, 0, 0, 0, 0,    
			0,                   
			0,                   
			0,                   
			0, 0, 0, 0,          
			32,                  
			0,                   
			0,                   
			PFD_MAIN_PLANE,      
			0,                   
			0, 0, 0              
		};

		int iPixelFormat = ChoosePixelFormat(hDC, &pfd);
		SetPixelFormat(hDC, iPixelFormat, &pfd);

	}

}