#include "OpenGLVertexBuffer.h"
#include "../../OpenGL/OpenGL.h"

namespace Onfer {

	OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, size_t size) {

		gl::GenBuffers(1, &m_ID);
		gl::BindBuffer(gl::ArrayBuffer, m_ID);
		gl::BufferData(gl::ArrayBuffer, size, data, gl::StaticDraw);
		gl::BindBuffer(gl::ArrayBuffer, 0); // <- ?

	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(size_t size) {
	
		gl::GenBuffers(1, &m_ID);
		gl::BindBuffer(gl::ArrayBuffer, m_ID);
		gl::BufferData(gl::ArrayBuffer, size, nullptr, gl::DynamicDraw);
		gl::BindBuffer(gl::ArrayBuffer, 0); // <- ?

	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer() {

		gl::DeleteBuffers(1, &m_ID);

	}

	void OpenGLVertexBuffer::sendData(const void* data, size_t size, uint32_t offset) {

		gl::BufferSubData(gl::ArrayBuffer, offset, size, data);

	}

	void OpenGLVertexBuffer::bind() {

		gl::BindBuffer(gl::ArrayBuffer, m_ID);
	
	}

	void OpenGLVertexBuffer::unbind() {

		gl::BindBuffer(gl::ArrayBuffer, 0);

	}

}