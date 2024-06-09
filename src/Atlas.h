#pragma once

#include <graphics.h>

#include <vector>

class Atlas
{
public:
	Atlas();
	~Atlas();
private:
	std::vector<IMAGE> imgList;
public:
	void LoadFromFile(LPCTSTR filepath, int num);
	void Clear();
	int GetSize();
	IMAGE* GetImage(int idx);
	void AddImage(IMAGE& img);
};