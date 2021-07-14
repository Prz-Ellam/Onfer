#include "Sprite.h"
#include "../OpenGL/OpenGLTexture.h"
#include "../BufferLayout.h"

namespace Onfer {

	Sprite::Sprite(vec3 position, vec3 scale, float rotation, const std::string& texture, vec4 color)
	: m_Position(position), m_Rotation(rotation), m_Scale(scale) {

		m_Quad = new Quad(color.x, color.y, color.z, color.w);
		m_Texture = new OpenGLTexture(texture);

	}

	Sprite::~Sprite() {

		delete m_Texture;
		delete m_Quad;

	}

	mat4 Sprite::getTransform() {

		return translate(m_Position) * rotateZ(m_Rotation) * scale(m_Scale);

	}

	vec3& Sprite::getPositionRef() {
	
		return m_Position;
	
	}

	vec3& Sprite::getScaleRef() {
	
		return m_Scale;
	
	}

	float& Sprite::getRotationRef() {
	
		return m_Rotation;
	
	}

	Vertex2D* Sprite::getTransformQuad() {

		// Optimizing soon
		aux = m_Quad->vertexData;

		aux[0].coords = (getTransform() * vec4(aux[0].coords.x, aux[0].coords.y, aux[0].coords.z, 1.0f));
		aux[1].coords = (getTransform() * vec4(aux[1].coords.x, aux[1].coords.y, aux[1].coords.z, 1.0f));
		aux[2].coords = (getTransform() * vec4(aux[2].coords.x, aux[2].coords.y, aux[2].coords.z, 1.0f));
		aux[3].coords = (getTransform() * vec4(aux[3].coords.x, aux[3].coords.y, aux[3].coords.z, 1.0f));

		return aux.data();

	}
}