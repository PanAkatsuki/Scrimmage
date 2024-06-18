#include "SunBullet.h"

// Default
SunBullet::SunBullet()
{
	// Bullet Init
	Vector2 size = { 96, 96 };
	SetSize(size);
	SetDamage(2);

	// Animation Init
	animation_sun.SetInterval(6);
	animation_sun.SetAtlas(&atlas_sun);

	animation_sun_explode.SetInterval(6);
	animation_sun_explode.SetLoop(false);
	animation_sun_explode.SetAtlas(&atlas_sun_explode);
	animation_sun_explode.SetCallBack(
		[&]()
		{
			can_remove = true;
		}
	);

	// Offset
	IMAGE* frame_sun = animation_sun.GetFrame();
	IMAGE* frame_sun_explode = animation_sun_explode.GetFrame();
	explode_render_offset.x = (frame_sun->getwidth() - frame_sun_explode->getwidth()) / 2;
	explode_render_offset.y = (frame_sun->getheight() - frame_sun_explode->getheight()) / 2;
}

void SunBullet::Update(int& delta)
{
	if (valid)
	{
		velocity.y += gravity * delta;
		if (velocity.y >= max_velocity_y)
		{
			velocity.y = max_velocity_y;
			if(velocity.x > 0)
			{
				velocity.x = 1;
			}
			else
			{
				velocity.x = -1;
			}
		}
		position.x += velocity.x;
		position.y += velocity.y * delta;
	}

	if (!valid)
	{
		animation_sun_explode.Update(delta);
	}
	else
	{
		animation_sun.Update(delta);
	}

	if (CheckBulletExceedsScreen())
	{
		can_remove = true;
	}
}

void SunBullet::Draw(Camera& camera) const
{
	if (valid)
	{
		animation_sun.Draw(camera, position.x, position.y);
	}
	else
	{
		animation_sun_explode.Draw(camera, position.x + explode_render_offset.x, position.y + explode_render_offset.y);
	}

	Bullet::Draw(camera);
}

void SunBullet::Collide() const
{
	Bullet::Collide();

	camera.Shake(1, 10);

	mciSendStringW(_T("play sun_explode from 0"), NULL, 0, NULL);
}