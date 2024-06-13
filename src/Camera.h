#pragma once

#include "Vector2.h"
#include "Timer.h"

class Camera
{
public:
	Camera();
	~Camera() = default;
private:
	// Set
	Vector2 position = { 0, 0 };

	// Shake
	Timer timer_shake;
	bool is_shaking = false;
	int shaking_strength = 0;
public:
	// Default
	void Update(int& delta);
public:
	// Set
	void SetPosition(int x, int y);
	Vector2 GetPosition() const;
	
	// Shake
	void Shake(int strength, int duration);
};