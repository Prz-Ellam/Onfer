#include "BufferLayout.h"

namespace Onfer {

	Vertex2D::Vertex2D(vec3 coords, vec4 colour, vec2 texCoords) 
		: coords(coords), colour(colour), texCoords(texCoords) {
	
	};

	Vertex2D::Vertex2D() {}

	BufferLayout::BufferLayout(uint32_t index, DataType type) 
		: index(index), type(type), size(getDataTypeSize(type)), count(getDataCount(type)) {
	
	};

	size_t BufferLayout::getDataTypeSize(DataType type) {
	
		switch (type) {
			case DataType::Float:	return sizeof(float);
			case DataType::Float2:	return sizeof(float) * 2;
			case DataType::Float3:	return sizeof(float) * 3;
			case DataType::Float4:	return sizeof(float) * 4;
		}

	}

	uint32_t BufferLayout::getDataCount(DataType type) {

		switch (type) {
			case DataType::Float:	return 1;
			case DataType::Float2:	return 2;
			case DataType::Float3:	return 3;
			case DataType::Float4:	return 4;
		}

	}

}

