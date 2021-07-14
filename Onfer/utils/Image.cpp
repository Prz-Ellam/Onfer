#include "Image.h"
#include <Windows.h>
#include <gdiplus.h>

namespace Onfer {

	Image::Image(const std::string& filePath) {

		Gdiplus::GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;

		Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
		{
			std::wstring wFilePath = std::wstring(filePath.begin(), filePath.end());
			Gdiplus::Bitmap bitmap(wFilePath.c_str());
			Gdiplus::BitmapData* bitmapData = new Gdiplus::BitmapData();

			m_Width = bitmap.GetWidth();
			m_Height = bitmap.GetHeight();

			Gdiplus::Rect rect(0, 0, m_Width, m_Height);

			bitmap.LockBits(&rect, Gdiplus::ImageLockModeRead, PixelFormat32bppARGB, bitmapData);

			m_Data = new RGBA[m_Width * m_Height];
			RGBA* pixels = (RGBA*)bitmapData->Scan0;
			memcpy(m_Data, (uint8_t*)bitmapData->Scan0, m_Width * m_Height * 4);

			for (unsigned int i = 0; i < m_Height * m_Width; i++)
			{
				m_Data[(m_Height * m_Width) - i - 1].b = pixels[i].r;
				m_Data[(m_Height * m_Width) - i - 1].g = pixels[i].g;
				m_Data[(m_Height * m_Width) - i - 1].r = pixels[i].b;
				m_Data[(m_Height * m_Width) - i - 1].a = pixels[i].a;
			}

			bitmap.UnlockBits(bitmapData);
			delete bitmapData;
		}
		Gdiplus::GdiplusShutdown(gdiplusToken);
	}

	Image::~Image() {

		delete[] m_Data;

	}

	uint32_t Image::getHeight() {

		return m_Height;

	}

	uint32_t Image::getWidth() {

		return m_Width;

	}

	const uint8_t* Image::getData() {

		return (uint8_t*)m_Data;

	}

}