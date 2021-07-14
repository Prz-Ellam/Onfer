#ifndef ONFER_INDEX_BUFFER_FACTORY_H
#define ONFER_INDEX_BUFFER_FACTORY_H

#include "IndexBuffer.h"

namespace Onfer {

	class IndexBufferFactory {
	public:
		static IndexBuffer* createIndexBuffer(const void* data, uint32_t count);
		static IndexBuffer* createIndexBuffer(uint32_t count);
	private:
		IndexBufferFactory() = default;
	};

}

#endif