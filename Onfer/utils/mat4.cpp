#include "mat4.h"
#include "vec3.h"
#include <cmath>

#define radians(x) x * 3.141592 / 180

namespace Onfer {

	mat4::mat4() : elements() {

	}

	mat4::mat4(const mat4& other) {

		if (this != &other) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					this->elements[i + j * 4] = other.elements[i + j * 4];
				}
			}
		}

	}

	mat4::~mat4() {

	}

	void mat4::identity() {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->elements[i + j * 4] = (i == j) ? 1 : 0;
			}
		}

	}

	void mat4::translate(const vec3& t) {

		this->identity();
		this->elements[3] = t.x;
		this->elements[7] = t.y;
		this->elements[11] = t.z;

	}

	void mat4::scale(const vec3& s) {
	
		this->identity();
		this->elements[0] = s.x;
		this->elements[5] = s.y;
		this->elements[10] = s.z;
	
	}

	void mat4::rotateX(float angle) {
	
		this->identity();
		this->elements[5] = std::cosf(radians(angle));
		this->elements[6] = std::sinf(radians(angle));
		this->elements[9] = -std::sinf(radians(angle));
		this->elements[10] = std::cosf(radians(angle));
	
	}

	void mat4::rotateY(float angle) {
	
		identity();
		this->elements[0] = std::cosf(radians(angle));
		this->elements[2] = -std::sinf(radians(angle));
		this->elements[8] = std::sinf(radians(angle));
		this->elements[10] = std::cosf(radians(angle));

	}

	void mat4::rotateZ(float angle) {
	
		identity();
		this->elements[0] = std::cos(radians(angle));
		this->elements[1] = std::sin(radians(angle));
		this->elements[4] = -std::sin(radians(angle));
		this->elements[5] = std::cos(radians(angle));
	
	}

	void mat4::setOrthographic(float left, float right, float bottom, float top, float _near, float _far) {

		this->identity();
		this->elements[0] = 2.0f / (right - left);
		this->elements[3] = -(right + left) / (right - left);
		this->elements[5] = 2.0f / (top - bottom);
		this->elements[7] = -(top + bottom) / (top - bottom);
		this->elements[10] = -2.0f / (_far - _near);
		this->elements[11] = -(_far + _near) / (_far - _near);

	}

	void mat4::setPerspective(float fov, float __, float _near, float _far) {}

	mat4 mat4::lookAt(const vec3& position, const vec3& forward, const vec3& up, const vec3& right) {
	
		mat4 matrix1;
		matrix1.identity();
		matrix1.vectors[0] = vec4(right, 1.0f);
		matrix1.vectors[1] = vec4(up, 1.0f);
		matrix1.vectors[2] = vec4(forward, 1.0f);
		
		mat4 matrix2;
		matrix2.translate(vec3(-position));
	
		return matrix1 * matrix2;

	}

	mat4 mat4::operator+(const mat4& other) {
	
		mat4 exit;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				exit.elements[i + j * 4] = this->elements[i + j * 4] + other.elements[i + j * 4];
			}
		}
		return exit;
	
	}

	mat4 mat4::operator-(const mat4& other) {
	
		mat4 exit;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				exit.elements[i + j * 4] = this->elements[i + j * 4] - other.elements[i + j * 4];
			}
		}
		return exit;
	
	}

	mat4 mat4::operator*(const mat4& other) {
	
		mat4 exit;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					exit.elements[i + j * 4] += this->elements[i + k * 4] * other.elements[k + j * 4];
				}
			}
		}
		return exit;
	
	}

	vec4 mat4::operator*(const vec4& vec) {
	/*
		00 01 02 03    X
		10 11 12 13    Y
		20 21 22 23    Z
		30 31 32 33    W
	*/
		vec4 exit;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				exit.elements[i] += this->elements[j + i * 4] * vec.elements[j];
			}
		}
		return exit;
	
	}

	mat4& mat4::operator+=(const mat4& other) {
	
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->elements[i + j * 4] += other.elements[i + j * 4];
			}
		}
		return *this;

	}

	mat4& mat4::operator-=(const mat4& other) {
	
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->elements[i + j * 4] -= other.elements[i + j * 4];
			}
		}
		return *this;
	
	}

	mat4& mat4::operator*=(const mat4& other) {
	
		mat4 exit;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					exit.elements[i + j * 4] += this->elements[i + k * 4] * other.elements[k + j * 4];
				}
			}
		}
		*this = exit;
		return *this;
	
	}

	void mat4::operator=(const mat4& other) {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->elements[i + j * 4] = other.elements[i + j * 4];
			}
		}

	}

	vec4 mat4::operator[](uint32_t row) {

		return vectors[row];

	}

	const float* mat4::data() const {

		return elements;

	}

	mat4 identity() {

		mat4 exit;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				exit.elements[i + j * 4] = (i == j) ? 1 : 0;
			}
		}

		return exit;

	}

	mat4 translate(const vec3& t) {

		mat4 exit;
		exit.identity();
		exit.elements[3] = t.x;
		exit.elements[7] = t.y;
		exit.elements[11] = t.z;
		return exit;

	}

	mat4 scale(const vec3& s) {

		mat4 exit;
		exit.identity();
		exit.elements[0] = s.x;
		exit.elements[5] = s.y;
		exit.elements[10] = s.z;
		return exit;

	}

	mat4 rotateX(float angle) {

		mat4 exit;
		exit.identity();
		exit.elements[5] = std::cosf(radians(angle));
		exit.elements[6] = std::sinf(radians(angle));
		exit.elements[9] = -std::sinf(radians(angle));
		exit.elements[10] = std::cosf(radians(angle));
		return exit;

	}

	mat4 rotateY(float angle) {

		mat4 exit;
		exit.identity();
		exit.elements[0] = std::cosf(radians(angle));
		exit.elements[2] = -std::sinf(radians(angle));
		exit.elements[8] = std::sinf(radians(angle));
		exit.elements[10] = std::cosf(radians(angle));
		return exit;

	}

	mat4 rotateZ(float angle) {

		mat4 exit;
		exit.identity();
		exit.elements[0] = std::cos(radians(angle));
		exit.elements[1] = std::sin(radians(angle));
		exit.elements[4] = -std::sin(radians(angle));
		exit.elements[5] = std::cos(radians(angle));
		return exit;

	}
	
}