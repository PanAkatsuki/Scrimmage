#pragma once

#include <graphics.h>

#include "Vector2.h"
#include "Atlas.h"

#include "PutImageAlpha.h"

class Particle
{
public:
	Particle() = default;
	~Particle() = default;
private:
	Atlas* atlas = nullptr;
	Vector2 position;
	int lifespan = 0;
	bool valid = true;

	int timer = 0;
	int idx_frame = 0;
	
public:
	// Default
	void Update(int& delta);
	void Draw(Camera& camera);
public:
	// Set
	void SetAtlas(Atlas* atlas);
	void SetPosition(int x, int y);
	void SetLifespan(int val);

	// Check
	bool CheckValid();
};