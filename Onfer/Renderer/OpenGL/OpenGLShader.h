#ifndef ONFER_OPENGL_SHADER_H
#define ONFER_OPENGL_SHADER_H

#include "../Shader.h"
#include <string>

namespace Onfer {

	class OpenGLShader : public Shader {
	public:
		OpenGLShader(const std::string& vert, const std::string& frag);
		virtual ~OpenGLShader();
		void bind() override;
		void unbind() override;
		void setMat4(const std::string& uniform, const mat4 data) override;
		void setInt1(const std::string& uniform, int data) override;
	private:
		uint32_t createShader(uint32_t shaderType, const std::string& file);
		std::string readShaderFromFile(const std::string& filePath);
	};

}

#endif