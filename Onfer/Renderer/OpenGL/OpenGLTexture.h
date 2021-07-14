#ifndef ONFER_OPENGL_TEXTURE_H
#define ONFER_OPENGL_TEXTURE_H

#include "../Texture.h"
#include <string>
#include <stdint.h>

namespace Onfer {

	class OpenGLTexture : public Texture {
	public:
		OpenGLTexture(const std::string& filePath);
		~OpenGLTexture();
		void bind(uint32_t slot) override;
		void unbind() override;
	};

}

#endif