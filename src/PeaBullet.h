#pragma once

#include "Bullet.h"
#include "Animation.h"

extern IMAGE img_pea;
extern Atlas atlas_pea_break;

extern Camera camera;

class PeaBullet : public Bullet
{
public:
	PeaBullet();
	~PeaBullet() = default;
private:
	Animation animation_break;
public:
	void Update(int& delta);
	void Draw(Camera& camera) const;
public:
	void Collide() const;
};