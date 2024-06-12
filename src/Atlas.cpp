#include "Atlas.h"

// Modifiers
void Atlas::LoadFromFile(LPCTSTR filepath, int num)
{
	img_list.resize(num);

	TCHAR path[256];
	for (int i = 0; i < num; i++)
	{
		_stprintf_s(path, filepath, i + 1);
		loadimage(&img_list[i], path, 0, 0, false);
	}
}

void Atlas::AddImage(IMAGE& img)
{
	img_list.push_back(img);
}

void Atlas::Clear()
{
	img_list.clear();
}

// Get
int Atlas::GetSize()
{
	return (int)img_list.size();
}

IMAGE* Atlas::GetImage(int idx)
{
	if (idx < 0 || idx >= img_list.size())
	{
		return nullptr;
	}
	return &img_list[idx];
}
