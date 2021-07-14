#include "OpenGLIndexBuffer.h"
#include "../../OpenGL/OpenGL.h"

namespace Onfer {

	OpenGLIndexBuffer::OpenGLIndexBuffer(const void* data, uint32_t count) {

		gl::GenBuffers(1, &m_ID);
		gl::BindBuffer(gl::ElementArrayBuffer, m_ID);
		gl::BufferData(gl::ElementArrayBuffer, sizeof(uint32_t) * count, data, gl::StaticDraw);
		gl::BindBuffer(gl::ElementArrayBuffer, 0);

	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t count) {

		gl::GenBuffers(1, &m_ID);
		gl::BindBuffer(gl::ElementArrayBuffer, m_ID);
		gl::BufferData(gl::ElementArrayBuffer, sizeof(uint32_t) * count, nullptr, gl::DynamicDraw);
		gl::BindBuffer(gl::ElementArrayBuffer, 0);

	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer() {

		gl::DeleteBuffers(1, &m_ID);

	}

	void OpenGLIndexBuffer::sendData(const void* data, uint32_t count, uint32_t offset) {

		gl::BufferSubData(gl::ElementArrayBuffer, offset, count * sizeof(uint32_t), data);

	}

	void OpenGLIndexBuffer::bind() {

		gl::BindBuffer(gl::ElementArrayBuffer, m_ID);

	}

	void OpenGLIndexBuffer::unbind() {

		gl::BindBuffer(gl::ElementArrayBuffer, 0);

	}

}