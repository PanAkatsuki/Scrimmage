#include "StatusBar.h"

// Default
void StatusBar::Draw()
{
	PutImageAlpha(position.x, position.y, img_avatar);

	setfillcolor(RGB(5, 5, 5));
	solidroundrect(position.x + 100, position.y + 10, position.x + 100 + width + 3 * 2, position.y + 36, 8, 8);
	solidroundrect(position.x + 100, position.y + 45, position.x + 100 + width + 3 * 2, position.y + 71, 8, 8);
	setfillcolor(RGB(67, 47, 47));
	solidroundrect(position.x + 100, position.y + 10, position.x + 100 + width + 3, position.y + 33, 8, 8);
	solidroundrect(position.x + 100, position.y + 45, position.x + 100 + width + 3, position.y + 68, 8, 8);

	float hp_bar_width = width * max(0, hp) / 100.0f;
	float mp_bar_width = width * min(100, mp) / 100.0f;

	setfillcolor(RGB(197, 61, 67));
	solidroundrect(position.x + 100, position.y + 10, position.x + 100 + (int)hp_bar_width + 3, position.y + 33, 8, 8);
	setfillcolor(RGB(83, 131, 195));
	solidroundrect(position.x + 100, position.y + 45, position.x + 100 + (int)mp_bar_width + 3, position.y + 68, 8, 8);
}

// Set
void StatusBar::SetHP(int val)
{
	hp = val;
}

void StatusBar::SetMP(int val)
{
	mp = val;
}

void StatusBar::SetAvatar(IMAGE* img)
{
	img_avatar = img;
}

void StatusBar::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}