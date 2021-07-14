#ifndef ONFER_OPENGL_INDEX_BUFFER_H
#define ONFER_OPENGL_INDEX_BUFFER_H

#include "../IndexBuffer.h"

namespace Onfer {

	class OpenGLIndexBuffer : public IndexBuffer {
	public:
		OpenGLIndexBuffer(const void* data, uint32_t count);
		OpenGLIndexBuffer(uint32_t count);
		~OpenGLIndexBuffer();
		void sendData(const void* data, uint32_t count, uint32_t offset) override;
		void bind() override;
		void unbind() override;
	};

}

#endif