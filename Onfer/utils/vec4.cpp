#include "vec4.h"
#include "vec3.h"
#include "vec2.h"

namespace Onfer {

	vec4::vec4() : elements() {
		
	}

	vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(x) {

	}

	vec4::vec4(const vec4& other) : elements() {

		if (this != &other) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;
		}

	}

	vec4::vec4(const vec3& other, float w) : x(other.x), y(other.y), z(other.z), w(w) {

	}

	vec4::vec4(const vec2& other, float z, float w) : x(other.x), y(other.y), z(z), w(w) {

	}

	vec4::vec4(const vec2& other1, const vec2& other2) : x(other1.x), y(other1.y), z(other2.x), w(other2.y) {

	}

	vec4::~vec4() {

	}

	vec4 vec4::operator+(const vec4& other) {

		return vec4(this->x + other.x,
					this->y + other.y,
					this->z + other.z,
					this->w + other.w);

	}

	vec4 vec4::operator-(const vec4& other) {

		return vec4(this->x - other.x,
					this->y - other.y,
					this->z - other.z,
					this->w - other.w);

	}

	float vec4::dot(const vec4& other) {

		return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;

	}

	vec4& vec4::operator+=(const vec4& other) {

		if (this != &other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			this->w += other.w;
		}
		return *this;

	}

	vec4& vec4::operator-=(const vec4& other) {

		if (this != &other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			this->w -= other.w;
		}
		return *this;

	}

	void vec4::operator=(const vec4& other) {

		if (this != &other) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;
		}

	}

	bool vec4::operator==(const vec4& other) {

		return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;

	}

	bool vec4::operator!=(const vec4& other) {

		return this->x == other.x || this->y == other.y || this->z == other.z || this->w == other.w;

	}

	float vec4::magnitude() const {

		return std::sqrt(this->x * this->x + 
						this->y * this->y + 
						this->z * this->z +	
						this->w * this->w);

	}

	vec4 vec4::normalize() {

		float mag = this->magnitude();
		return vec4(this->x / mag, this->y / mag, this->z / mag, this->w / mag);

	}

	float vec4::operator[](uint32_t index) {

		return elements[index];

	}

	vec4 operator*(float scalar, const vec4& other) {

		return vec4(scalar * other.x, scalar * other.y, scalar * other.z, scalar * other.w);

	}

	float dot(const vec4& u, const vec4& v) {

		return u.x * v.x + u.y * v.y + u.z * v.z * u.w * v.w;

	}

	vec4 normalize(const vec4& v) {

		float mag = v.magnitude();
		return vec4(v.x / mag, v.y / mag, v.z / mag, v.w / mag);

	}

}