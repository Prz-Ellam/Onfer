#ifndef ONFER_CAMERA_3D_H
#define ONFER_CAMERA_3D_H

#include "../../utils/Math.h"
#include "../../source/KeyEvents.h"
#include "../Camera.h"

namespace Onfer {

	class Camera3D : public ICamera {
	public:
		Camera3D(uint32_t width, uint32_t height, float fov, float _near, float _far, float speed, float sensitivity);

		void move() override;

		vec3 getPosition() const override;
		void setPosition(vec3& position) override;

		float getSpeed() const override;
		void setSpeed(float speed) override;

		float getSensitivity() const;
		void setSensitivity(float sensitivity);

		mat4 getProjection() override;
		mat4 getView() override;

	private:
		vec3 m_Position;
		vec3 m_Forward, m_Up, m_Right;
		float m_Speed;
		float m_Sensitivity;
		float m_Pitch, m_Yaw, m_Roll; // Roll en desuso

		mat4 m_Projection;
		mat4 m_View;
	};

}

#endif