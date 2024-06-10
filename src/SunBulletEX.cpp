#include "SunBulletEX.h"

SunBulletEX::SunBulletEX()
{
	// Bullet Init
	Vector2 size = { 288, 288 };
	SetSize(size);
	SetDamage(3);

	// Animation Init
	animation_sun_ex.SetInterval(6);
	animation_sun_ex.SetAtlas(&atlasSunEX);

	animation_sun_ex_explode.SetInterval(6);
	animation_sun_ex_explode.SetLoop(false);
	animation_sun_ex_explode.SetAtlas(&atlasSunEXExplode);
	animation_sun_ex_explode.SetCallBack(
		[&]()
		{
			can_remove = true;
		}
	);

	// Offset
	IMAGE* frame_sun_ex = animation_sun_ex.GetFrame();
	IMAGE* frame_sun_ex_explode = animation_sun_ex_explode.GetFrame();
	explode_render_offset.x = (frame_sun_ex->getwidth() - frame_sun_ex_explode->getwidth()) / 2;
	explode_render_offset.y = (frame_sun_ex->getheight() - frame_sun_ex_explode->getheight()) / 2;
}

void SunBulletEX::Update(int& delta)
{
	if (valid)
	{
		position.y += velocity.y * delta;
	}

	if (!valid)
	{
		animation_sun_ex_explode.Update(delta);
	}
	else
	{
		animation_sun_ex.Update(delta);
	}

	if (CheckBulletExceedsScreen())
	{
		can_remove = true;
	}
}

void SunBulletEX::Draw(Camera& camera) const
{
	if (valid)
	{
		animation_sun_ex.Draw(camera, position.x, position.y);
	}
	else
	{
		animation_sun_ex_explode.Draw(camera, position.x + explode_render_offset.x, position.y + explode_render_offset.y);
	}
}

void SunBulletEX::Collide()
{
	Bullet::Collide();

	camera.Shake(10, 3);

	mciSendStringW(_T("play sun_explode_ex from 0"), NULL, 0, NULL);
}
bool SunBulletEX::CheckCollistion(Vector2& position, Vector2& size)
{
	bool is_collide_x = (max(this->position.x + this->size.x, position.x + size.x)
		- min(this->position.x, position.x)) <= this->size.x + size.x;
	bool is_collide_y = (max(this->position.y + this->size.y, position.y + size.y)
		- min(this->position.y, position.x)) <= this->size.y + size.y;

	return is_collide_x && is_collide_y;
}