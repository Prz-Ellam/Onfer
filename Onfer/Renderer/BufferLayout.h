#ifndef ONFER_BUFFER_LAYOUT_H
#define ONFER_BUFFER_LAYOUT_H

#include <stdint.h>
#include <unordered_map>
#include "../utils/Math.h"

namespace Onfer {

	enum class DataType {
		Float,
		Float2,
		Float3,
		Float4
	}; 

	class Vertex2D {
	public:
		Vertex2D(vec3 coords, vec4 colour, vec2 texCoords);
		Vertex2D();
		vec3 coords;
		vec4 colour;
		vec2 texCoords;
	};

	class BufferLayout {
	public:
		BufferLayout(uint32_t index, DataType type);
		static size_t getDataTypeSize(DataType type);
		static size_t getDataCount(DataType type);
		uint32_t index;
		DataType type;
		uint32_t count;
		size_t size;
	};

}

#endif