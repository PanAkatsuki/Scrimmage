#pragma once

#include <graphics.h>

#include <vector>

class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;
private:
	// Container
	std::vector<IMAGE> img_list;
public:
	// Modifiers
	void LoadFromFile(LPCTSTR filepath, int num);
	void AddImage(IMAGE& img);
	void Clear();

	// Get
	int GetSize();
	IMAGE* GetImage(int idx);
};