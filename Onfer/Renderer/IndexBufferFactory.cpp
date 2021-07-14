#include "IndexBufferFactory.h"
#include "OpenGL/OpenGLIndexBuffer.h"

namespace Onfer {

	IndexBuffer* IndexBufferFactory::createIndexBuffer(const void* data, uint32_t count) {

		// In the future support to DirectX, for the moment only OpenGL
		return new OpenGLIndexBuffer(data, count);

	}

	IndexBuffer* IndexBufferFactory::createIndexBuffer(uint32_t count) {

		return new OpenGLIndexBuffer(count);

	}

}