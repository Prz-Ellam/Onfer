#ifndef ONFER_VEC4_H
#define ONFER_VEC4_H

#include <stdint.h>

namespace Onfer {

	class vec2;
	class vec3;

	class vec4 {
	public:
		vec4();
		vec4(float x, float y, float z, float w);
		vec4(const vec4& other);
		vec4(const vec3& other, float w);
		vec4(const vec2& other, float z, float w);
		vec4(const vec2& other1, const vec2& other2);
		~vec4();

		vec4 operator+(const vec4& other);
		vec4 operator-(const vec4& other);
		void operator=(const vec4& other);

		float dot(const vec4& other);
		   
		vec4& operator+=(const vec4& other);
		vec4& operator-=(const vec4& other);

		bool operator==(const vec4& other);
		bool operator!=(const vec4& other);

		float magnitude() const;
		vec4 normalize();

		float operator[](uint32_t index);

		union {
			struct { float x, y, z, w; };
			float elements[4];
		};
	};

	vec4 operator*(float scalar, const vec4& other);
	float dot(const vec4& u, const vec4& v);
	vec4 normalize(const vec4& v);

}

#endif