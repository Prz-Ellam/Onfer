#include "OpenGLVertexArray.h"
#include "../../OpenGL/OpenGL.h"

namespace Onfer {

	OpenGLVertexArray::OpenGLVertexArray() {

		gl::GenVertexArrays(1, &m_ID);

	}

	OpenGLVertexArray::~OpenGLVertexArray() {

		gl::DeleteVertexArrays(1, &m_ID);
		
	}

	void OpenGLVertexArray::attachVertexBuffer(VertexBuffer* vb, std::vector<BufferLayout> layouts) {

		gl::BindVertexArray(m_ID);
		vb->bind();

		uint32_t stride = 0;
		for (const auto& layout : layouts) {
			
			gl::EnableVertexAttribArray(layout.index);
			gl::VertexAttribPointer(layout.index, layout.count, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (const void*)stride);
			stride += layout.size;

		}
		gl::BindVertexArray(0);

	}

	void OpenGLVertexArray::attachVertexBuffer(VertexBuffer* vb, BufferLayout layout) {

		gl::BindVertexArray(m_ID);
		vb->bind();

		gl::EnableVertexAttribArray(layout.index);
		gl::VertexAttribPointer(layout.index, layout.size, (GLenum)layout.type, GL_FALSE, sizeof(Vertex2D), (const void*)0);

		gl::BindVertexArray(0);

	}

	void OpenGLVertexArray::attachIndexBuffer(IndexBuffer* ib) {

		gl::BindVertexArray(m_ID);
		ib->bind();
		gl::BindVertexArray(0);

	}

	void OpenGLVertexArray::bind() {

		gl::BindVertexArray(m_ID);

	}

	void OpenGLVertexArray::unbind() {

		gl::BindVertexArray(0);

	}

}