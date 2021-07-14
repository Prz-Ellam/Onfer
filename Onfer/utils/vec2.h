#ifndef ONFER_VEC2_H
#define ONFER_VEC2_H

#include <stdint.h>

namespace Onfer {

	class vec4;
	class vec3;

	class vec2 {
	public:
		vec2();
		vec2(float x, float y);
		vec2(const vec2& other);
		~vec2();

		vec2 operator+(const vec2& other);
		vec2 operator-(const vec2& other);

		void operator=(const vec2& other);
		void operator=(const vec3& other);
		void operator=(const vec4& other);

		float dot(const vec2& other);

		vec2& operator+=(const vec2& other);
		vec2& operator-=(const vec2& other);

		bool operator==(const vec2& other);
		bool operator!=(const vec2& other);

		float magnitude() const;
		vec2 normalize();

		float operator[](uint32_t index);

		union {
			struct { float x, y; };
			float elements[2];
		};
	};

	vec2 operator*(float scalar, const vec2& other);
	float dot(const vec2& u, const vec2& v);
	vec2 normalize(const vec2& v);

}

#endif