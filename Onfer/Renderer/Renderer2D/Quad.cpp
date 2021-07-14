#include "Quad.h"

namespace Onfer {

	uint32_t Quad::s_QuadCounts = 0;

	Quad::Quad(float r, float g, float b, float a) {
	
		vertexData[0] = Vertex2D(vec3(-0.5f, -0.5f, 0.0f),	vec4(r, g, b, a),	vec2(0.0f, 0.0f));
		vertexData[1] = Vertex2D(vec3( 0.5f, -0.5f, 0.0f),	vec4(r, g, b, a),	vec2(1.0f, 0.0f));
		vertexData[2] = Vertex2D(vec3( 0.5f,  0.5f, 0.0f),	vec4(r, g, b, a),	vec2(1.0f, 1.0f));
		vertexData[3] = Vertex2D(vec3(-0.5f,  0.5f, 0.0f),	vec4(r, g, b, a),	vec2(0.0f, 1.0f));

		indexData[0] = indexData[5] = s_QuadCounts * 4;
		indexData[1] = s_QuadCounts * 4 + 1;
		indexData[2] = indexData[3] = s_QuadCounts * 4 + 2;
		indexData[4] = s_QuadCounts * 4 + 3;
		s_QuadCounts++;

	}

	Quad::Quad(float x, float y, float width, float height, float r, float g, float b, float a) {

		vertexData[0] = Vertex2D(vec3(x, y, 0.0f), vec4(r, g, b, a), vec2(0.0f, 0.0f));
		vertexData[1] = Vertex2D(vec3(x + width, y, 0.0f), vec4(r, g, b, a), vec2(1.0f, 0.0f));
		vertexData[2] = Vertex2D(vec3(x + width, y + height, 0.0f), vec4(r, g, b, a), vec2(1.0f, 1.0f));
		vertexData[3] = Vertex2D(vec3(x, y + height, 0.0f), vec4(r, g, b, a), vec2(0.0f, 1.0f));

		indexData[0] = indexData[5] = s_QuadCounts * 4;
		indexData[1] = s_QuadCounts * 4 + 1;
		indexData[2] = indexData[3] = s_QuadCounts * 4 + 2;
		indexData[4] = s_QuadCounts * 4 + 3;
		s_QuadCounts++;

	}

	Vertex2D* Quad::getVertexData() {

		return vertexData.data();

	}

	uint32_t* Quad::getIndexData() {

		return indexData.data();

	}

}