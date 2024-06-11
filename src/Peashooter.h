#pragma once

#include <iostream>

#include "Player.h"

#include "PeaBullet.h"

extern Atlas atlasPeashooterIdleLeft;
extern Atlas atlasPeashooterIdleRight;
extern Atlas atlasPeashooterRunLeft;
extern Atlas atlasPeashooterRunRight;

class Peashooter : public Player
{
public:
	Peashooter();
	~Peashooter() = default;
private:
	int speed_pea = 8;
	int speed_pea_ex = 12;

	const int attack_ex_duration = 120;
private:
	Timer timer_attack_ex;
	Timer timer_spwan_pea_ex;
public:
	void Update(int delta);
	//void Draw(Camera& camera);
public:
	void Attack();
	void AttackEX();
private:
	void SpawnPeaBullet(int& speed);
};