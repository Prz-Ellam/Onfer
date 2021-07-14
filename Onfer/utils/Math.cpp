
#if 0
/*
#define radians(x) x * 3.141592 / 180

namespace Onfer {

	vec2::vec2(float x, float y) : x(x), y(y) {

	}

	vec2 vec2::operator=(const vec3& vec) {

		this->x = vec.x;
		this->y = vec.y;

		return *this;

	}

	vec2 vec2::operator=(const vec4& vec) {

		this->x = vec.x;
		this->y = vec.y;

		return *this;

	}

	vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {

	}

	float vec4::operator[](uint32_t position) {

		return m_Elements[position];

	}

	//mat4 mat4::setIdentityMatrix() {

	//	mat4 identity = {};

	//	identity.m_Elements[0] = 1.0f;
	//	identity.m_Elements[5] = 1.0f;
	//	identity.m_Elements[10] = 1.0f;
	//	identity.m_Elements[15] = 1.0f;

	//	return identity;

	//}

	mat4::mat4() : m_Elements() {

	}

	mat4::mat4(const mat4& other) : m_Elements() {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m_Elements[i + j * 4] = other.m_Elements[i + j * 4];
			}
		}
	}

	float mat4::getElements(uint32_t row, uint32_t column) {

		return m_Elements[row + column * 4];

	}

	void mat4::setElement(uint32_t row, uint32_t column, float element) {

		m_Elements[row + column * 4] = element;

	}

	mat4 mat4::translateMatrix(vec3 t) {

		mat4 translate = {};

		translate.m_Elements[0] = 1.0f;
		translate.m_Elements[5] = 1.0f;
		translate.m_Elements[10] = 1.0f;
		translate.m_Elements[15] = 1.0f;
		translate.m_Elements[3] = t.x;
		translate.m_Elements[7] = t.y;
		translate.m_Elements[11] = t.z;

		return translate;

	}

	mat4 mat4::scaleMatrix(vec3 s) {

		mat4 scale = {};

		scale.m_Elements[0] = s.x;
		scale.m_Elements[5] = s.y;
		scale.m_Elements[10] = s.z;
		scale.m_Elements[15] = 1.0f;

		return scale;

	}

	//mat4 mat4::setOrtho(float left, float right, float bottom, float top, float near, float far) {

	//	mat4 ortho = {};

	//	ortho.m_Elements[0] = 2.0f / (right - left);
	//	ortho.m_Elements[3] = - (right + left) / (right - left);
	//	ortho.m_Elements[5] = 2.0f / (top - bottom);
	//	ortho.m_Elements[7] = -(top + bottom) / (top - bottom);
	//	ortho.m_Elements[10] = -2.0f / (far - near);
	//	ortho.m_Elements[11] = -(far + near) / (far - near);
	//	ortho.m_Elements[15] = 1;

	//	return ortho;

	//}

	void mat4::setOrthographic(float left, float right, float bottom, float top, float near, float far) {

		setIdentity();
		m_Elements[0] = 2.0f / (right - left);
		m_Elements[3] = -(right + left) / (right - left);
		m_Elements[5] = 2.0f / (top - bottom);
		m_Elements[7] = -(top + bottom) / (top - bottom);
		m_Elements[10] = -2.0f / (far - near);
		m_Elements[11] = -(far + near) / (far - near);

	}

	void mat4::setTranslate(vec3 t) {

		setIdentity();
		m_Elements[3] = t.x;
		m_Elements[7] = t.y;
		m_Elements[11] = t.z;

	}

	void mat4::setScale(vec3 s) {

		setIdentity();
		m_Elements[0] = s.x;
		m_Elements[5] = s.y;
		m_Elements[10] = s.z;

	}

	void mat4::setRotationX(float rx) {

		setIdentity();
		m_Elements[1 + 1 * 4] = cos(radians(rx));
		m_Elements[1 + 2 * 4] = -sin(radians(rx));
		m_Elements[2 + 1 * 4] = sin(radians(rx));
		m_Elements[2 + 2 * 4] = cos(radians(rx));

	}

	void mat4::setRotationY(float ry) {

		setIdentity();
		m_Elements[0 + 0 * 4] = cos(radians(ry));
		m_Elements[2 + 0 * 4] = -sin(radians(ry));
		m_Elements[0 + 2 * 4] = sin(radians(ry));
		m_Elements[2 + 2 * 4] = cos(radians(ry));

	}

	void mat4::setRotationZ(float rz) {

		setIdentity();
		m_Elements[0 + 0 * 4] = cos(radians(rz));
		m_Elements[0 + 1 * 4] = -sin(radians(rz));
		m_Elements[1 + 0 * 4] = sin(radians(rz));
		m_Elements[1 + 1 * 4] = cos(radians(rz));

	}

	void mat4::setIdentity() {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				m_Elements[i + j * 4] = (i == j) ? 1 : 0;
			}
		}

	}

	const float* mat4::data() {

		return m_Elements;

	}

	vec4 mat4::operator[](uint32_t row) {

		return m_Elements2[row];

	}

	mat4 mat4::operator+(const mat4& other) {

		mat4 exit = {};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				exit.m_Elements[i + j * 4] = this->m_Elements[i + j * 4] + other.m_Elements[i + j * 4];
			}
		}

		return exit;

	}

	mat4& mat4::operator+=(const mat4& other) {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->m_Elements[i + j * 4] += other.m_Elements[i + j * 4];
			}
		}

		return *this;

	}

	mat4& mat4::operator-=(const mat4& other) {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				this->m_Elements[i + j * 4] -= other.m_Elements[i + j * 4];
			}
		}

		return *this;

	}

	mat4 mat4::operator-(const mat4& other) {

		mat4 exit = {};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				exit.m_Elements[i + j * 4] = this->m_Elements[i + j * 4] - other.m_Elements[i + j * 4];
			}
		}

		return exit;

	}

	mat4 mat4::operator*(const mat4& other) {

		mat4 exit = {};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					exit.m_Elements[i + j * 4] += this->m_Elements[i + k * 4] * other.m_Elements[k + j * 4];
				}
			}
		}

		return exit;

	}

	mat4& mat4::operator*=(const mat4& other) {

		mat4 exit;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					exit.m_Elements[i + j * 4] += this->m_Elements[i + k * 4] * other.m_Elements[k + j * 4];
				}
			}
		}
		*this = exit;

		return *this;

	}

	vec4 mat4::operator*(const vec4& vec) {

		vec4 exit;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				exit.m_Elements[i] += this->m_Elements[i + j * 4] * vec.m_Elements[j];
			}
		}

		return exit;

	}

	mat4 mat4::multiplyScalarMat4(float scalar, const mat4& mat) {

		mat4 exit;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				exit.m_Elements[i + j * 4] = scalar * mat.m_Elements[i + j * 4];
			}
		}

		return exit;

	}

	mat4 operator*(float scalar, const mat4& mat) {

		return mat4::multiplyScalarMat4(scalar, mat);

	}
}
*/
#endif