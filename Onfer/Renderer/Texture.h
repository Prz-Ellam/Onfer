#ifndef ONFER_TEXTURE_H
#define ONFER_TEXTURE_H

#include <stdint.h>

namespace Onfer {

	class Texture {
	public:
		virtual ~Texture() {};
		virtual void bind(uint32_t slot) = 0;
		virtual void unbind() = 0;
	protected:
		Texture() = default;
		uint32_t m_ID;
	};

}

#endif