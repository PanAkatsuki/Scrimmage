#pragma once

#include <graphics.h>

#include "PutImageAlpha.h"

class StatusBar
{
public:
	StatusBar() = default;
	~StatusBar() = default;
private:
	const int width = 275;
private:
	int hp = 0;
	int mp = 0;

	IMAGE* img_avatar = nullptr;
	POINT position = { 0, 0 };
public:
	void Draw();
public:
	// Set
	void SetHP(int val);
	void SetMP(int val);
	void SetAvatar(IMAGE* img);
	void SetPosition(int x, int y);
};