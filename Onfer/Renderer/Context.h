#ifndef ONFER_CONTEXT_H
#define ONFER_CONTEXT_H

namespace Onfer {

	class Context {
	protected:
		Context() {};
	public:
		virtual void makeContextCurrent() = 0;
		virtual void swapBuffers() = 0;
	};

}

#endif