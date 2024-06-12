#include "Peashooter.h"

// Constructor
Peashooter::Peashooter()
{
	//mp = 100;

	animation_idel_left.SetAtlas(&atlasPeashooterIdleLeft);
	animation_idel_right.SetAtlas(&atlasPeashooterIdleRight);
	animation_run_left.SetAtlas(&atlasPeashooterRunLeft);
	animation_run_right.SetAtlas(&atlasPeashooterRunRight);
	animation_attack_ex_left.SetAtlas(&atlasPeashooterAttackEXLeft);
	animation_attack_ex_right.SetAtlas(&atlasPeashooterAttackEXRight);

	animation_idel_left.SetInterval(6);
	animation_idel_right.SetInterval(6);
	animation_run_left.SetInterval(6);
	animation_run_right.SetInterval(6);
	animation_attack_ex_left.SetInterval(6);
	animation_attack_ex_right.SetInterval(6);

	SetSize(96, 96);

	timer_attack_ex.SetWaitTime(attack_ex_duration);
	timer_attack_ex.SetOneShot(true);
	timer_attack_ex.SetCallback(
		[&]()
		{
			is_attack_ex = false;
		}
	);

	timer_spwan_pea_ex.SetWaitTime(10);
	timer_spwan_pea_ex.SetCallback(
		[&]()
		{
			SpawnPeaBullet(speed_pea_ex);
		}
	);
}

void Peashooter::Update(int& delta)
{
	Player::Update(delta);

	if (is_attack_ex)
	{
		camera.Shake(5, 120);
		timer_attack_ex.Update(delta);
		timer_spwan_pea_ex.Update(delta);
	}
}

void Peashooter::Attack()
{
	SpawnPeaBullet(speed_pea);

	// play sound
	switch (rand() % 2)
	{
	case 0:
		mciSendStringW(_T("play pea_shoot_1 from 0"), NULL, 0, NULL);
		break;
	case 1:
		mciSendStringW(_T("play pea_shoot_2 from 0"), NULL, 0, NULL);
		break;
	}
}
void Peashooter::AttackEX()
{
	is_attack_ex = true;
	timer_attack_ex.Reset();

	is_facing_right ? animation_attack_ex_right.Reset() : animation_attack_ex_left.Reset();

	mciSendStringW(_T("play pea_shoot_ex from 0"), NULL, 0, NULL);
}

void Peashooter::SpawnPeaBullet(int speed)
{
	// new bullet
	Bullet* bullet = new PeaBullet();

	// set bullet target
	Player* target_player = ((id == PlayerID::P1) ? player_2 : player_1);

	switch (target_player->GetId())
	{
	case PlayerID::P1:
		bullet->SetTargetID(PlayerID::P1);
		break;
	case PlayerID::P2:
		bullet->SetTargetID(PlayerID::P2);
		break;
	}

	// set bullet position
	Vector2 bullet_position;
	Vector2 bullet_size = bullet->GetSize();
	bullet_position.x = is_facing_right ? position.x + size.x - bullet_size.x / 2 : position.x + bullet_size.x / 2;
	bullet_position.y = position.y + bullet_size.y;
	bullet->SetPosition(bullet_position);

	// set bullet velocity
	Vector2 bullet_velocity;
	bullet_velocity.x = is_facing_right ? speed : -speed;
	bullet_velocity.y = 0;
	bullet->SetVelocity(bullet_velocity);

	// set bullet callback
	bullet->SetCallback([&]() { mp += 10; });

	// push back bullet
	bullet_list.push_back(bullet);
}