#ifndef ONFER_VERTEX_BUFFER_H
#define ONFER_VERTEX_BUFFER_H

#include <stdint.h>

namespace Onfer {

	class VertexBuffer {
	public:

		virtual void sendData(const void* data, size_t size, uint32_t offset) = 0;
		virtual void bind() = 0;
		virtual void unbind() = 0;

	protected:
		VertexBuffer() = default;
		virtual ~VertexBuffer() {};
		uint32_t m_ID;	
	};

}

#endif