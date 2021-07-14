#ifndef ONFER_OPENGL_VERTEX_BUFFER_H
#define ONFER_OPENGL_VERTEX_BUFFER_H

#include "../VertexBuffer.h"

namespace Onfer {

	class OpenGLVertexBuffer : public VertexBuffer {
	public:
		OpenGLVertexBuffer(const void* data, size_t size);
		OpenGLVertexBuffer(size_t size);
		~OpenGLVertexBuffer();
		void sendData(const void* data, size_t size, uint32_t offset) override;
		void bind() override;
		void unbind() override;
	};

}

#endif