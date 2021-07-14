#ifndef ONFER_CAMERA_H
#define ONFER_CAMERA_H

#include "../utils/Math.h"

namespace Onfer {

	class ICamera {
	public:
		ICamera() = default;
		virtual void move() = 0;
		virtual vec3 getPosition() const = 0;
		virtual void setPosition(vec3& position) = 0;
		virtual float getSpeed() const = 0;
		virtual void setSpeed(float speed) = 0;
		virtual mat4 getProjection() = 0;
		virtual mat4 getView() = 0;
	};

}

#endif