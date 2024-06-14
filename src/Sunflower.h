#pragma once

#include <iostream>

#include "Player.h"
#include "SunBullet.h"
#include "SunBulletEX.h"

extern Atlas atlas_sunflower_idle_left;
extern Atlas atlas_sunflower_idle_right;
extern Atlas atlasSunflowerRunLeft;
extern Atlas atlasSunflowerRunRight;
extern Atlas atlasSunflowerAttackEXLeft;
extern Atlas atlasSunflowerAttackEXRight;
extern Atlas atlasSunText;

extern Player* player_1;
extern Player* player_2;

class Sunflower : public Player
{
public:
	Sunflower();
	~Sunflower() = default;
private:
	const int velocity_sun_ex_y = 4;
	const int velocity_sun_x = 10;
	const int velocity_sun_y = 20;
private:
	Animation animation_sun_text;
	bool is_sun_text_visible = false;
public:
	void Update(int& delta);
	void Draw(Camera& camera);
public:
	void SpawnSunBullet();
	void Attack();
	void SpawnSunBulletEX();
	void AttackEX();
public:
	
	
};