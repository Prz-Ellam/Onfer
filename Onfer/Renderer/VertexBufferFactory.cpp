#include "VertexBufferFactory.h"
#include "OpenGL/OpenGLVertexBuffer.h"

namespace Onfer {

	VertexBuffer* VertexBufferFactory::createVertexBuffer(const void* data, size_t size) {

		// In the future support to DirectX, for the moment only OpenGL
		return new OpenGLVertexBuffer(data, size);

	}

	VertexBuffer* VertexBufferFactory::createVertexBuffer(size_t size) {
	
		return new OpenGLVertexBuffer(size);
	
	}

}