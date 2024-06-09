#pragma once

#include <iostream>

#include "Player.h"

extern Atlas atlasSunflowerIdleLeft;
extern Atlas atlasSunflowerIdleRight;
extern Atlas atlasSunflowerRunLeft;
extern Atlas atlasSunflowerRunRight;

class Sunflower : public Player
{
public:
	Sunflower()
	{
		animation_idel_left.SetAtlas(&atlasSunflowerIdleLeft);
		animation_idel_right.SetAtlas(&atlasSunflowerIdleRight);
		animation_run_left.SetAtlas(&atlasSunflowerIdleLeft);
		animation_run_right.SetAtlas(&atlasSunflowerIdleRight);

		animation_idel_left.SetInterval(100);
		animation_idel_right.SetInterval(100);
		animation_run_left.SetInterval(100);
		animation_run_right.SetInterval(100);
	}
	~Sunflower() = default;
private:

public:
	void Update(int delta);
};