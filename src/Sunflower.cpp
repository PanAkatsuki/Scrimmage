#include "Sunflower.h"

Sunflower::Sunflower()
{
	animation_idel_left.SetAtlas(&atlasSunflowerIdleLeft);
	animation_idel_right.SetAtlas(&atlasSunflowerIdleRight);
	animation_run_left.SetAtlas(&atlasSunflowerIdleLeft);
	animation_run_right.SetAtlas(&atlasSunflowerIdleRight);
	animation_attack_ex_left.SetAtlas(&atlasSunflowerAttackEXLeft);
	animation_attack_ex_right.SetAtlas(&atlasSunflowerAttackEXRight);
	animation_sun_text.SetAtlas(&atlasSunText);

	animation_idel_left.SetInterval(6);
	animation_idel_right.SetInterval(6);
	animation_run_left.SetInterval(6);
	animation_run_right.SetInterval(6);
	animation_attack_ex_left.SetInterval(6);
	animation_attack_ex_right.SetInterval(6);
	animation_sun_text.SetInterval(6);

	animation_attack_ex_left.SetLoop(false);
	animation_attack_ex_right.SetLoop(false);
	animation_sun_text.SetLoop(false);

	animation_attack_ex_left.SetCallBack(
		[&]()
		{
			is_attack_ex = false;
			is_sun_text_visible = false;
		}
	);
	animation_attack_ex_right.SetCallBack(
		[&]()
		{
			is_attack_ex = false;
			is_sun_text_visible = false;
		}
	);

	SetSize(96, 96);

}

void Sunflower::Update(int& delta)
{
	Player::Update(delta);

	if (is_sun_text_visible)
	{
		animation_sun_text.Update(delta);
	}
}
void Sunflower::Draw(Camera& camera)
{
	Player::Draw(camera);

	if (is_sun_text_visible)
	{
		IMAGE* img = animation_sun_text.GetFrame();
		animation_sun_text.Draw(camera, position.x - img->getwidth(), position.y - img->getheight());
	}
}

void Sunflower::SpawnSunBullet()
{
	// new bullet
	Bullet* bullet = new SunBullet();

	// set bullet position
	Vector2 bullet_position;
	Vector2 bullet_size = bullet->GetSize();
	bullet_position.x = position.x + (size.x - bullet_size.x) / 2;
	bullet_position.y = position.y;
	bullet->SetPosition(bullet_position);

	// set bullet velocity
	Vector2 bullet_velocity;
	if (is_facing_right)
	{
		bullet_velocity.x = velocity_sun_x;
	}
	else
	{
		bullet_velocity.x = -velocity_sun_x;
	}
	bullet_velocity.y = velocity_sun_y;
	bullet->SetVelocity(bullet_velocity);

	// set bullet target
	switch (id)
	{
	case PlayerID::P1:
		bullet->SetTargetID(PlayerID::P2);
		break;
	case PlayerID::P2:
		bullet->SetTargetID(PlayerID::P1);
		break;
	}

	// set bullet callback
	bullet->SetCallback(
		[&]()
		{
			mp += 0;
		}
	);

	// push back bullet
	bullet_list.push_back(bullet);
}
void Sunflower::Attack()
{
	SpawnSunBullet();

	// play sound
}
void Sunflower::SpawnSunBulletEX()
{
	// new bullet
	Bullet* bullet = new SunBulletEX();

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
	Vector2 target_position = target_player->GetPosition();

	bullet_position.x = target_position.x - bullet->GetSize().x / 2;
	bullet_position.y = target_position.x - bullet->GetSize().y - target_player->GetSize().y;
	bullet->SetPosition(bullet_position);

	// set bullet velocity
	Vector2 bullet_velocity = { 0, velocity_sun_ex_y };
	bullet->SetVelocity(bullet_velocity);

	// set bullet callback
	bullet->SetCallback(
		[&]()
		{
			mp += 50;
		}
	);

	// push back bullet
	bullet_list.push_back(bullet);
}
void Sunflower::AttackEX()
{
	SpawnSunBulletEX();

	// play sound
	mciSendStringW(_T("play sun_text from 0"), NULL, 0, NULL);

	// set bool
	is_attack_ex = true;
	is_sun_text_visible = true;

	// animation
	animation_sun_text.Reset();
	is_facing_right ? animation_attack_ex_right.Reset() : animation_attack_ex_left.Reset();

}

