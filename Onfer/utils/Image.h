#ifndef ONFER_IMAGE_H
#define ONFER_IMAGE_H

#include <stdint.h>
#include <string>

namespace Onfer {

	struct RGBA {
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};

	class Image {
	public:
		Image(const std::string& filePath);
		~Image();
		uint32_t getHeight();
		uint32_t getWidth();
		const uint8_t* getData();
	private:
		RGBA* m_Data;
		uint32_t m_Width, m_Height;
	};

}

#endif