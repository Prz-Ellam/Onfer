#ifndef ONFER_VERTEX_ARRAY_H
#define ONFER_VERTEX_ARRAY_H

#include <stdint.h>
#include <vector>
#include "VertexBuffer.h"
#include "BufferLayout.h"
#include "IndexBuffer.h"

namespace Onfer {

	class VertexArray {
	public:
		virtual void attachVertexBuffer(VertexBuffer* vb, std::vector<BufferLayout> layouts) = 0;
		virtual void attachVertexBuffer(VertexBuffer* vb, BufferLayout layout) = 0;
		virtual void attachIndexBuffer(IndexBuffer* ib) = 0;
		virtual void bind() = 0;
		virtual void unbind() = 0;
	protected:
		VertexArray() = default;
		virtual ~VertexArray() {};
		uint32_t m_ID;
	};

}

#endif