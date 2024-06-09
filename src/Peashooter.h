#pragma once

#include <iostream>

#include "Player.h"

extern Atlas atlasPeashooterIdleLeft;
extern Atlas atlasPeashooterIdleRight;
extern Atlas atlasPeashooterRunLeft;
extern Atlas atlasPeashooterRunRight;

class Peashooter : public Player
{
public:
	Peashooter()
	{
		animation_idel_left.SetAtlas(&atlasPeashooterIdleLeft);
		animation_idel_right.SetAtlas(&atlasPeashooterIdleRight);
		animation_run_left.SetAtlas(&atlasPeashooterRunLeft);
		animation_run_right.SetAtlas(&atlasPeashooterRunRight);

		animation_idel_left.SetInterval(6);
		animation_idel_right.SetInterval(6);
		animation_run_left.SetInterval(6);
		animation_run_right.SetInterval(6);
	}
	~Peashooter() = default;
private:

public:
	void Update(int delta);
};