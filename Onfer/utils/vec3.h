#ifndef ONFER_VEC3_H
#define ONFER_VEC3_H

#include <stdint.h>
#include <complex>

namespace Onfer {

	class vec4;
	class vec2;

	class vec3 {
	public:
		vec3();
		vec3(float x, float y, float z);
		vec3(const vec3& other);
		vec3(const vec4& other);
		vec3(const vec2& other, float z);
		~vec3();

		vec3 operator+(const vec3& other);
		vec3 operator-(const vec3& other);
		void operator=(const vec3& other);
		void operator=(const vec4& other);
		vec3 operator-() const;

		float dot(const vec3& other);
		vec3 cross(const vec3& other);

		vec3& operator+=(const vec3& other);
		vec3& operator-=(const vec3& other);

		bool operator==(const vec3& other);
		bool operator!=(const vec3& other);

		float magnitude() const;
		vec3 normalize();

		float operator[](uint32_t index);

		union {
			struct { float x, y, z; };
			float elements[3];
		};
	};

	vec3 operator*(float scalar, const vec3& other);
	float dot(const vec3& u, const vec3& v);
	vec3 cross(const vec3& u, const vec3& v);
	vec3 normalize(const vec3& v);

}

#endif