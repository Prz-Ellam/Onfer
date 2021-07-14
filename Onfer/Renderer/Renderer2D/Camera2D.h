#ifndef ONFER_CAMERA_2D_H
#define ONFER_CAMERA_2D_H

#include "../../utils/Math.h"
#include "../../source/KeyEvents.h"
#include "../Camera.h"

namespace Onfer {

	class Camera2D : public ICamera {
	public:
		Camera2D(float left, float right, float bottom, float top, float _near, float _far);

		void move(KeyEvents&e); // <- En desuso
		void move() override;

		vec3 getPosition() const override;
		void setPosition(vec3& position) override;

		float getSpeed() const override;
		void setSpeed(float speed) override;

		mat4 getProjection() override;
		mat4 getView() override;

		void setProjection(float left, float right, float bottom, float top, float _near, float _far);

	private:
		vec3 m_Position;
		float m_Rotation; // En desuso
		float m_Speed;

		mat4 m_Projection;
		mat4 m_View;
	};

}

#endif