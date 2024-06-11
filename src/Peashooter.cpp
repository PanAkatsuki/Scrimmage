#include "Peashooter.h"

// Constructor
Peashooter::Peashooter()
{
	animation_idel_left.SetAtlas(&atlasPeashooterIdleLeft);
	animation_idel_right.SetAtlas(&atlasPeashooterIdleRight);
	animation_run_left.SetAtlas(&atlasPeashooterRunLeft);
	animation_run_right.SetAtlas(&atlasPeashooterRunRight);

	animation_idel_left.SetInterval(6);
	animation_idel_right.SetInterval(6);
	animation_run_left.SetInterval(6);
	animation_run_right.SetInterval(6);

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

void Peashooter::Update(int delta)
{
	Player::Update(delta);

	std::cout << "Peashooter is updating" << std::endl;
}

void Peashooter::Attack()
{
	SpawnPeaBullet(speed_pea);

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
	timer_attack_ex.Restart();
}

void Peashooter::SpawnPeaBullet(int& speed)
{
	Bullet* bullet = new PeaBullet();
	Vector2 bullet_position;
	Vector2 bullet_velocity;

	Vector2 bullet_size = bullet->GetSize();
	bullet_position.x = is_facing_right ? position.x + size.x - bullet_size.x / 2 : position.x + bullet_size.x / 2;
	bullet_position.y = position.y + bullet_size.y;
	bullet_velocity.x = is_facing_right ? speed : -speed;
	bullet_velocity.y = 0;

	bullet->SetPosition(bullet_position);
	bullet->SetVelocity(bullet_velocity);
	switch (id)
	{
	case PlayerID::P1:
		bullet->SetTargetID(PlayerID::P2);
		break;
	case PlayerID::P2:
		bullet->SetTargetID(PlayerID::P1);
		break;
	}
	bullet->SetCallback([&]() { mp += 10; });

	bullet_list.push_back(bullet);
}