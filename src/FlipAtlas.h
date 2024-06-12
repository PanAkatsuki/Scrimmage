#pragma once

#include <graphics.h>

#include "Atlas.h"

class Flip
{
public:
	Flip() = default;
	~Flip() = default;
private:

};

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

inline void FlipAtlas(Atlas& src, Atlas& dst)
{
	dst.Clear();
	for (int i = 0; i < src.GetSize(); i++)
	{
		IMAGE imgFlipped;
		FlipImage(src.GetImage(i), &imgFlipped);
		dst.AddImage(imgFlipped);
	}
}