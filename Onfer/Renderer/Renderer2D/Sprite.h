#ifndef ONFER_SPRITE_H
#define ONFER_SPRITE_H

#include "../../utils/Math.h"
#include "../Texture.h"
#include "Quad.h"
#include <string>
#include <array>

namespace Onfer {

	class Sprite {
	public:
		Sprite(vec3 position, vec3 scale, float rotation, const std::string& texture, vec4 color);
		~Sprite();
		mat4 getTransform();

		Vertex2D* getTransformQuad();

		vec3& getPositionRef();
		vec3& getScaleRef();
		float& getRotationRef();

	private:
		std::array<Vertex2D, 4> aux;
		vec3 m_Position;
		vec3 m_Scale;
		float m_Rotation;
		Texture* m_Texture;
		Quad* m_Quad;
		// Position
		// Scale
		// Rotation
		// Texture
		// Quad
	};

}


#endif