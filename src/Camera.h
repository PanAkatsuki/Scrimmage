#pragma once

#include "Vector2.h"
#include "Timer.h"

class Camera
{
public:
	Camera();
	~Camera();
private:
	Vector2 pos;
	Timer timerShake;
	bool isShaking;
	float shakingStrength;
public:
	Vector2 GetPos() const;
	void Reset();
	void Update(int& delta);

	void Shake(float strength, int duration);
};