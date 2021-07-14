#include "../../OpenGL/OpenGL.h"
#include "OpenGLTexture.h"
#include "../../utils/Image.h"

namespace Onfer {

	OpenGLTexture::OpenGLTexture(const std::string& filePath) {

		Image image = Image(filePath);

		glGenTextures(1, &m_ID);
		glBindTexture(GL_TEXTURE_2D, m_ID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // GL_LINEAR
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image.getWidth(), image.getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getData());
		gl::GenerateMipmap(GL_TEXTURE_2D);

	}

	OpenGLTexture::~OpenGLTexture() {

		glDeleteTextures(1, &m_ID);

	}

	void OpenGLTexture::bind(uint32_t slot) {

		gl::ActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_ID);

	}

	void OpenGLTexture::unbind() {

		glBindTexture(GL_TEXTURE_2D, 0);

	}

}