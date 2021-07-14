#ifndef ONFER_MAT4_H
#define ONFER_MAT4_H

#include <stdint.h>
#include "vec4.h"

namespace Onfer {

	class vec3;

	class mat4 {
	public:
		mat4();
		mat4(const mat4& other);
		~mat4();

		void identity();
		void translate(const vec3& t);
		void scale(const vec3& s);
		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);

		void setOrthographic(float left, float right, float bottom, float top, float _near, float _far);
		void setPerspective(float fov, float __, float _near, float _far);
		mat4 lookAt(const vec3& position, const vec3& forward, const vec3& up, const vec3& right);

		mat4 operator+(const mat4& other);
		mat4 operator-(const mat4& other);
		mat4 operator*(const mat4& other);
		vec4 operator*(const vec4& vec);

		mat4& operator+=(const mat4& other);
		mat4& operator-=(const mat4& other);
		mat4& operator*=(const mat4& other);

		void operator=(const mat4& other);

		vec4 operator[](uint32_t row);

		const float* data() const; 

		union {
			float elements[16];
			vec4 vectors[4];
		};

	};

	mat4 operator*(float scalar, const mat4& mat);
	mat4 identity();
	mat4 translate(const vec3& t);
	mat4 scale(const vec3& s);
	mat4 rotateX(float angle);
	mat4 rotateY(float angle);
	mat4 rotateZ(float angle);

}

#endif