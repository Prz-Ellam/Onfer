#ifndef ONFER_SHADER_H
#define ONFER_SHADER_H

#include <stdint.h>
#include <string>
#include "../utils/Math.h"

namespace Onfer {

	class Shader {
	public:
		virtual ~Shader() {};
		virtual void bind() = 0;
		virtual void unbind() = 0;
		
		virtual void setMat4(const std::string& location, const mat4 data) = 0;
		virtual void setInt1(const std::string& location, int data) = 0;
	protected:
		Shader() = default;
		uint32_t m_ID;
	};

}

#endif