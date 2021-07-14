#include "OpenGLShader.h"
#include "../../OpenGL/OpenGL.h"
#include "../../utils/Log.h"
#include <sstream>
#include <fstream>
#include <string>

namespace Onfer {

	OpenGLShader::OpenGLShader(const std::string& vert, const std::string& frag) {

		m_ID = gl::CreateProgram();
		unsigned int vs = createShader(gl::VertexShader, vert);
		unsigned int fs = createShader(gl::FragmentShader, frag);

		gl::AttachShader(m_ID, vs);
		gl::AttachShader(m_ID, fs);
		gl::LinkProgram(m_ID);
		gl::ValidateProgram(m_ID);

		gl::DeleteShader(vs);
		gl::DeleteShader(fs);

		gl::UseProgram(m_ID);

	}

	OpenGLShader::~OpenGLShader() {

		gl::DeleteProgram(m_ID);

	}

	void OpenGLShader::bind() {

		gl::UseProgram(m_ID);

	}

	void OpenGLShader::unbind() {

		gl::UseProgram(0);

	}

	uint32_t OpenGLShader::createShader(uint32_t shaderType, const std::string& file) {

		unsigned int id = gl::CreateShader(shaderType);
		std::string sShader = readShaderFromFile(file);
		const char* cShader = sShader.c_str();
		gl::ShaderSource(id, 1, &cShader, nullptr);
		gl::CompileShader(id);

		int sucess;
		gl::GetShaderiv(id, GL_COMPILE_STATUS, &sucess);
		if (!sucess) {
			char info[512];
			gl::GetShaderInfoLog(id, 512, nullptr, info);
			Log::error("Error de compilacion");
			(shaderType == GL_VERTEX_SHADER) ? Log::error("Shader Type: Vertex Shader ") : Log::error("Shader Type: Fragment Shader ");
			Log::error(info);
		}
		
		return id;

	}

	std::string OpenGLShader::readShaderFromFile(const std::string& filePath) {

		std::ifstream file(filePath);

		if (!file.is_open()) {
			Log::error("El shader no pudo ser leido");
		}

		std::string buffer;
		std::stringstream source;

		while (!file.eof()) {
			std::getline(file, buffer);
			buffer += '\n';
			source << buffer;
		}

		buffer = source.str();
		return buffer;

	}

	void OpenGLShader::setMat4(const std::string& uniform, mat4 data) {
	
		int location = gl::GetUniformLocation(m_ID, uniform.c_str());
		gl::UniformMatrix4fv(location, 1, 1, data.data());
	
	}

	void OpenGLShader::setInt1(const std::string& uniform, int data) {

		int location = gl::GetUniformLocation(m_ID, uniform.c_str());
		gl::Uniform1i(location, data);

	}

}