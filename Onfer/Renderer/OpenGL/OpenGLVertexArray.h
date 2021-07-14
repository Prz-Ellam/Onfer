#ifndef ONFER_OPENGL_VERTEX_ARRAY
#define ONFER_OPENGL_VERTEX_ARRAY

#include "../VertexArray.h"
#include "../VertexBuffer.h"
#include "OpenGLVertexBuffer.h"
#include "../IndexBuffer.h"
#include "../BufferLayout.h"
#include <vector>

namespace Onfer {

	class OpenGLVertexArray : public VertexArray {
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void attachVertexBuffer(VertexBuffer* vb, std::vector<BufferLayout> layouts) override;
		void attachVertexBuffer(VertexBuffer* vb, BufferLayout layout) override;
		void attachIndexBuffer(IndexBuffer* ib) override;
		void bind() override;
		void unbind() override;

	};

}

#endif