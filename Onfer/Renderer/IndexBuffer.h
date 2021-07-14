#ifndef ONFER_INDEX_BUFFER_H
#define ONFER_INDEX_BUFFER_H

#include <stdint.h>

namespace Onfer {

	class IndexBuffer {
	public:
		virtual void bind() = 0;
		virtual void unbind() = 0;
		virtual void sendData(const void* data, uint32_t count, uint32_t offset) = 0;
	protected:
		IndexBuffer() = default;
		virtual ~IndexBuffer() {};
		uint32_t m_ID;
	};

}

#endif