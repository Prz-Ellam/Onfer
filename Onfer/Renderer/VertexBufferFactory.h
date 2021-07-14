#ifndef ONFER_VERTEX_BUFFER_FACTORY_H
#define ONFER_VERTEX_BUFFER_FACTORY_H

#include "VertexBuffer.h"

namespace Onfer {

	class VertexBufferFactory {
	public:
		static VertexBuffer* createVertexBuffer(const void* data, size_t size);
		static VertexBuffer* createVertexBuffer(size_t size);
	private:
		VertexBufferFactory() = delete;
	};

}

#endif