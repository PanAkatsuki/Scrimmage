#pragma once

#include "Player.h"

#include "PeaBullet.h"

extern Atlas atlas_peashooter_idle_left;
extern Atlas atlas_peashooter_idle_right;
extern Atlas atlas_peashooter_run_left;
extern Atlas atlas_peashooter_run_right;
extern Atlas atlas_peashooter_attack_ex_left;
extern Atlas atlas_peashooter_attack_ex_right;
extern Atlas atlas_peashooter_die_left;
extern Atlas atlas_peashooter_die_right;

extern Player* player_1;
extern Player* player_2;

class Peashooter : public Player
{
public:
	Peashooter();
	~Peashooter() = default;
private:
	const int speed_pea = 8;
	int speed_pea_ex = 12;

	const int attack_ex_duration = 180;
private:
	Timer timer_attack_ex;
	Timer timer_spwan_pea_ex;
public:
	void Update(int& delta);
	//void Draw(Camera& camera);
private:
	void SpawnPeaBullet(int speed);
public:
	void Attack();
	void AttackEX();
};