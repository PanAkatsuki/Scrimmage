#pragma once

#include "Util.h"

#include "Bullet.h"
#include "Animation.h"

extern IMAGE imgPea;
extern Atlas atlasPeaBreak;

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
	void Collide();
};