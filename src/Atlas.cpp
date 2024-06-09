#include "Atlas.h"

Atlas::Atlas()
{
	imgList.clear();
}
Atlas::~Atlas()
{

}

void Atlas::LoadFromFile(LPCTSTR filepath, int num)
{
	imgList.resize(num);

	TCHAR path[256];
	for (int i = 0; i < num; i++)
	{
		_stprintf_s(path, filepath, i + 1);
		loadimage(&imgList[i], path, 0, 0, false);
	}
}
void Atlas::Clear()
{
	imgList.clear();
}
int Atlas::GetSize()
{
	return (int)imgList.size();
}
IMAGE* Atlas::GetImage(int idx)
{
	if (idx < 0 || idx >= imgList.size())
	{
		return nullptr;
	}
	return &imgList[idx];
}
void Atlas::AddImage(IMAGE& img)
{
	imgList.push_back(img);
}