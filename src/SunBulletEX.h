#pragma once

#include "Bullet.h"
#include "Animation.h"

extern Atlas atlasSunEX;
extern Atlas atlasSunEXExplode;

extern Camera camera;

class SunBulletEX : public Bullet
{
public:
	SunBulletEX();
	~SunBulletEX() = default;
private:
	Animation animation_sun_ex;
	Animation animation_sun_ex_explode;
	Vector2 explode_render_offset;
public:
	void Update(int& delta);
	void Draw(Camera& camera) const;
public:
	void Collide();
	bool CheckCollistion(Vector2& position, Vector2& size);
};

