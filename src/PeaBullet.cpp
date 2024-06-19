#include "PeaBullet.h"

// Constructor
PeaBullet::PeaBullet()
{
	// Bullet Init
	Vector2 size = { 64, 64 };
	SetSize(size);
	SetDamage(10);

	// Animation Init
	animation_break.SetInterval(6);
	animation_break.SetLoop(false);
	animation_break.SetAtlas(&atlas_pea_break);
	animation_break.SetCallBack(
		[&]()
		{
			can_remove = true;
		}
	);
}

void PeaBullet::Update(int& delta)
{
	position.x += velocity.x * delta;
	position.y += velocity.y * delta;

	if (!valid)
	{
		animation_break.Update(delta);
	}

	if (CheckBulletExceedsScreen())
	{
		can_remove = true;
	}
}
void PeaBullet::Draw(Camera& camera) const
{
	if (valid)
	{
		PutImageAlpha(camera, position.x, position.y, &img_pea);
	}
	else
	{
		animation_break.Draw(camera, position.x, position.y);
	}

	Bullet::Draw(camera);
}

void PeaBullet::Collide() const
{
	Bullet::Collide();

	switch(rand() % 3)
	{
	case 0:
		mciSendStringW(_T("play pea_break_1 from 0"), NULL, 0, NULL);
		break;
	case 1:
		mciSendStringW(_T("play pea_break_2 from 0"), NULL, 0, NULL);
		break;
	case 2:
		mciSendStringW(_T("play pea_break_3 from 0"), NULL, 0, NULL);
		break;
	}
}