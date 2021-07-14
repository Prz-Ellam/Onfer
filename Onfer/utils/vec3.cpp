#include "vec3.h"
#include "vec4.h"
#include "vec2.h"

namespace Onfer {

	vec3::vec3() : elements() {

	}

	vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) {

	}

	vec3::vec3(const vec3& other) : elements() {

		if (this != &other) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
		}

	}

	vec3::vec3(const vec4& other) : x(other.x), y(other.y), z(other.z) {

	}

	vec3::vec3(const vec2& other, float z) : x(other.x), y(other.y), z(z) {

	}

	vec3::~vec3() {

	}

	vec3 vec3::operator+(const vec3& other) {
	
		return vec3(this->x + other.x, 
					this->y + other.y, 
					this->z + other.z);

	}

	vec3 vec3::operator-(const vec3& other) {
	
		return vec3(this->x - other.x,
					this->y - other.y, 
					this->z - other.z);

	}

	float vec3::dot(const vec3& other) {

		return this->x * other.x + this->y * other.y + this->z * other.z;

	}

	vec3 vec3::cross(const vec3& other) {

		return vec3(this->y * other.z - this->z * other.y,
					this->z * other.x - this->x * other.z,
					this->x * other.y - this->y * other.x);

	}

	vec3& vec3::operator+=(const vec3& other) {

		if (this != &other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}
		return *this;

	}

	vec3& vec3::operator-=(const vec3& other) {

		if (this != &other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
		}
		return *this;

	}

	void vec3::operator=(const vec3& other) {
	
		if (this != &other) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
		}

	}

	void vec3::operator=(const vec4& other) {

		this->x = other.x;
		this->y = other.y;
		this->z = other.z;

	}

	vec3 vec3::operator-() const {

		vec3 exit;
		exit.x = -this->x;
		exit.y = -this->y;
		exit.z = -this->z;
		return exit;

	}

	bool vec3::operator==(const vec3& other) {

		return this->x == other.x && this->y == other.y && this->z == other.z;

	}

	bool vec3::operator!=(const vec3& other) {

		return this->x == other.x || this->y == other.y || this->z == other.z;

	}

	float vec3::magnitude() const {

		return std::sqrt(this->x * this->x + 
						this->y * this->y + 
						this->z * this->z);

	}

	vec3 vec3::normalize() {

		float mag = this->magnitude();
		return vec3(this->x / mag, this->y / mag, this->z / mag);

	}

	float vec3::operator[](uint32_t index) {

		return elements[index];

	}

	vec3 operator*(float scalar, const vec3& other) {

		return vec3(scalar * other.x, scalar * other.y, scalar * other.z);

	}

	float dot(const vec3& u, const vec3& v) {

		return u.x * v.x + u.y * v.y + u.z * v.z;

	}

	vec3 cross(const vec3& u, const vec3& v) {

		return vec3(u.y * v.z - u.z * v.y,
			u.z * v.x - u.x * v.z,
			u.x * v.y - u.y * v.x);

	}

	vec3 normalize(const vec3& v) {

		float mag = v.magnitude();
		return vec3(v.x / mag, v.y / mag, v.z / mag);

	}

}