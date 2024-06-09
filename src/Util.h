#pragma once

#include <graphics.h>

#include "Camera.h"

class Util
{
public:
	Util() = default;
	~Util() = default;
};

inline void DebugLine(Camera& camera, int x1, int y1, int x2, int y2)
{
	Vector2 pos_camera = camera.GetPos();
	line(x1 - pos_camera.x, y1 - pos_camera.y, x2 - pos_camera.x, y2 - pos_camera.y);
}

inline void FlipImage(IMAGE* src, IMAGE* dst)
{
	int w = src->getwidth();
	int h = src->getheight();
	Resize(dst, w, h);
	DWORD* srcBuffer = GetImageBuffer(src);
	DWORD* dstBuffer = GetImageBuffer(dst);
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int srcIdx = y * w + x;
			int dstIdx = y * w + w - x - 1;
			dstBuffer[dstIdx] = srcBuffer[srcIdx];
		}
	}
}

#pragma comment(lib, "MSIMG32.LIB")
inline void PutImageAlpha(int dstx, int dsty, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(GetWorkingImage()), dstx, dsty, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}
inline void PutImageAlpha(Camera& camera, int dstx, int dsty, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(GetWorkingImage()), (dstx - camera.GetPos().x), (dsty - camera.GetPos().y), w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}
inline void PutImageAlpha(int dstx, int dsty, int width, int height, IMAGE* img, int srcx, int srcy)
{
	int w = width > 0 ? width : img->getwidth();
	int h = height > 0 ? height : img->getheight();
	AlphaBlend(GetImageHDC(GetWorkingImage()), dstx, dsty, w, h,
		GetImageHDC(img), srcx, srcy, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}