#include "vec2.h"
#include <complex>

namespace Onfer {

	vec2::vec2() : elements() {

	}

	vec2::vec2(float x, float y) : x(x), y(y) {

	}

	vec2::vec2(const vec2& other) : elements() {

		if (this != &other) {
			this->x = other.x;
			this->y = other.y;
		}

	}

	vec2::~vec2() {

	}

	vec2 vec2::operator+(const vec2& other) {

		return vec2(this->x + other.x,
					this->y + other.y);

	}

	vec2 vec2::operator-(const vec2& other) {

		return vec2(this->x - other.x,
					this->y - other.y);

	}

	float vec2::dot(const vec2& other) {

		return this->x * other.x + this->y * other.y;

	}

	vec2& vec2::operator+=(const vec2& other) {

		if (this != &other) {
			this->x += other.x;
			this->y += other.y;
		}
		return *this;

	}

	vec2& vec2::operator-=(const vec2& other) {

		if (this != &other) {
			this->x -= other.x;
			this->y -= other.y;
		}
		return *this;

	}

	void vec2::operator=(const vec2& other) {

		if (this != &other) {
			this->x = other.x;
			this->y = other.y;
		}

	}

	bool vec2::operator==(const vec2& other) {

		return this->x == other.x && this->y == other.y;

	}

	bool vec2::operator!=(const vec2& other) {

		return this->x == other.x || this->y == other.y;

	}

	float vec2::magnitude() const {

		return std::sqrt(this->x * this->x +
						this->y * this->y);

	}

	vec2 vec2::normalize() {

		float mag = this->magnitude();
		return vec2(this->x / mag, this->y / mag);

	}

	float vec2::operator[](uint32_t index) {

		return elements[index];

	}

	vec2 operator*(float scalar, const vec2& other) {

		return vec2(scalar * other.x, scalar * other.y);

	}

	float dot(const vec2& u, const vec2& v) {

		return u.x * v.x + u.y * v.y;

	}

	vec2 normalize(const vec2& v) {

		float mag = v.magnitude();
		return vec2(v.x / mag, v.y / mag);

	}

}