#pragma once

#include "Bullet.h"
#include "Animation.h"

extern Atlas atlasSun;
extern Atlas atlasSunExplode;

extern Camera  camera;

class SunBullet : public Bullet
{
public:
	SunBullet();
	~SunBullet() = default;
private:
	int gravity = 1;
private:
	Animation animation_sun;
	Animation animation_sun_explode;
	Vector2 explode_render_offset;
public:
	void Update(int& delta);
	void Draw(Camera& camera) const;
public:
	void Collide();
};