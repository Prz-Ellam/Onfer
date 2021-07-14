#include "Camera2D.h"
#include <Windows.h>

namespace Onfer {

	Camera2D::Camera2D(float left, float right, float bottom, float top, float _near, float _far) 
		: m_Position(0.0f, 0.0f, 0.0f), m_Rotation(0), m_Speed(0.01f) {

		m_Projection.setOrthographic(left, right, bottom, top, _near, _far);
		m_View.identity();

	}

	void Camera2D::move() {

		if (IsKeyPressed(KeyCode::KeyW)) {
			m_Position.y += m_Speed;
		}
		if (IsKeyPressed(KeyCode::KeyA)) {
			m_Position.x -= m_Speed;
		}
		if (IsKeyPressed(KeyCode::KeyS)) {
			m_Position.y -= m_Speed;
		}
		if (IsKeyPressed(KeyCode::KeyD)) {
			m_Position.x += m_Speed;
		}

		m_View.translate(m_Position);

	}

	void Camera2D::move(KeyEvents& e) {

		if (e.getKeyStatus(KeyCode::KeyW).isKeyPress()) {
			m_Position.y += m_Speed;
		}
		if (e.getKeyStatus(KeyCode::KeyA).isKeyPress()) {
			m_Position.x -= m_Speed;
		}
		if (e.getKeyStatus(KeyCode::KeyS).isKeyPress()) {
			m_Position.y -= m_Speed;
		}
		if (e.getKeyStatus(KeyCode::KeyD).isKeyPress()) {
			m_Position.x += m_Speed;
		}

		m_View.translate(m_Position);

	}

	vec3 Camera2D::getPosition() const {
	
		return m_Position;
	
	}

	void Camera2D::setPosition(vec3& position) {
	
		m_Position = position;
	
	}

	float Camera2D::getSpeed() const {
	
		return m_Speed;
	
	}

	void Camera2D::setSpeed(float speed) {
	
		m_Speed = speed;
	
	}

	void Camera2D::setProjection(float left, float right, float bottom, float top, float _near, float _far) {

		m_Projection.setOrthographic(left, right, bottom, top, _near, _far);

	}

	mat4 Camera2D::getProjection() {

		return m_Projection;

	}

	mat4 Camera2D::getView() {

		return m_View;

	}

}