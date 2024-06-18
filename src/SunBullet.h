#pragma once

#include "Bullet.h"
#include "Animation.h"

extern Atlas atlas_sun;
extern Atlas atlas_sun_explode;

extern Camera camera;

class SunBullet : public Bullet
{
public:
	SunBullet();
	~SunBullet() = default;
private:
	int gravity = 1;
	int max_velocity_y = 5;
private:
	Animation animation_sun;
	Animation animation_sun_explode;
	Vector2 explode_render_offset;
public:
	// Default
	void Update(int& delta);
	void Draw(Camera& camera) const;
public:
	void Collide() const;
};