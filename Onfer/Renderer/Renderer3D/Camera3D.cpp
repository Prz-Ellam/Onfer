#include "Camera3D.h"
#include <Windows.h>

namespace Onfer {

	Camera3D::Camera3D(uint32_t width, uint32_t height, float fov, float _near, float _far, float speed, float sensitivity) 
		: m_Position(0.0f, 0.0f, 0.0f), m_Speed(speed), m_Sensitivity(sensitivity) {



	}

	void Camera3D::move() {

		if (IsKeyPressed(KeyCode::KeyW)) {
			m_Position += m_Speed * m_Forward;
		}
		if (IsKeyPressed(KeyCode::KeyS)) {
			m_Position -= m_Speed * m_Forward;
		}
		if (IsKeyPressed(KeyCode::KeyA)) {
			m_Position -= m_Speed * m_Right;
		}
		if (IsKeyPressed(KeyCode::KeyD)) {
			m_Position += m_Speed * m_Right;
		}

	}

	vec3 Camera3D::getPosition() const {

		return m_Position;

	}

	void Camera3D::setPosition(vec3& position) {
	
		m_Position = position;

	}

	float Camera3D::getSpeed() const {

		return m_Speed;

	}

	void Camera3D::setSpeed(float speed) {

		m_Speed = speed;

	}

	float Camera3D::getSensitivity() const {

		return m_Sensitivity;

	}

	void Camera3D::setSensitivity(float sensitivity) {

		m_Sensitivity = sensitivity;

	}

	mat4 Camera3D::getProjection() {
	
		return m_Projection;

	}

	mat4 Camera3D::getView() {

		return m_View;

	}


}