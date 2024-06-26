#pragma once

#include "Bullet.h"
#include "Animation.h"

extern Atlas atlas_sun_ex;
extern Atlas atlas_sun_ex_explode;

extern Camera camera;

class SunBulletEX : public Bullet
{
public:
	SunBulletEX();
	~SunBulletEX() = default;
private:
	// Animation
	Animation animation_sun_ex;
	Animation animation_sun_ex_explode;

	// Offset
	Vector2 explode_render_offset;
public:
	void Update(int& delta);
	void Draw(Camera& camera) const;
public:
	void Collide() const;
	bool CheckCollistion(Vector2& position, Vector2& size);
};

