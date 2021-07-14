#ifndef ONFER_QUAD_H
#define ONFER_QUAD_H

#include "../VertexBuffer.h"
#include "../IndexBuffer.h"
#include <array>
#include "../BufferLayout.h"

namespace Onfer {

#define VERTEX_QUAD_SIZE sizeof(Vertex2D) * 4
#define INDEX_QUAD_SIZE sizeof(uint32_t) * 6
#define INDEX_QUAD_COUNT 6

	class Quad {
	public:
		friend class Sprite;
		Quad(float r, float g, float b, float a);
		Quad(float x, float y, float width, float height, float r, float g, float b, float a);
		Vertex2D* getVertexData();
		uint32_t* getIndexData();
	private:
		std::array<Vertex2D, 4> vertexData;
		std::array<uint32_t, 6> indexData;
		static uint32_t s_QuadCounts; // Global counter of the Quads to batch them together in a single draw call
		//VertexBuffer* vbo;
		//IndexBuffer* ibo;
		// Vertex Array
		// Store a Vertex Buffer with Position, Colour, Texture Coordinates and Texture ID
		// Index Buffer
	};

}

#endif