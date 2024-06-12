#pragma once

#include <graphics.h>

#include "Camera.h"

class Alpha
{
public:
	Alpha() = default;
	~Alpha() = default;
private:

};

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
	AlphaBlend(GetImageHDC(GetWorkingImage()), (dstx - camera.GetPosition().x), (dsty - camera.GetPosition().y), w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}
inline void PutImageAlpha(int dstx, int dsty, int width, int height, IMAGE* img, int srcx, int srcy)
{
	int w = width > 0 ? width : img->getwidth();
	int h = height > 0 ? height : img->getheight();
	AlphaBlend(GetImageHDC(GetWorkingImage()), dstx, dsty, w, h,
		GetImageHDC(img), srcx, srcy, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}