#include "Camera.h"

// Constructor
Camera::Camera()
{
	timer_shake.SetCallback(
		[&]()
		{
			is_shaking = false;
			timer_shake.Reset();
			shaking_strength = 0;
		}
	);
}

// Set
void Camera::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

Vector2 Camera::GetPosition() const
{
	return position;
}
void Camera::Reset()
{
	position.x = 0;
	position.y = 0;
}
void Camera::Update(int& delta)
{
	if (is_shaking)
	{
		timer_shake.Update(delta);
		position.x = (-50 + rand() % 100) / 50 * shaking_strength;
		position.y = (-50 + rand() % 100) / 50 * shaking_strength;
	}
}

void Camera::Shake(int strength, int duration)
{
	is_shaking = true;
	shaking_strength = strength;

	timer_shake.Reset();
	timer_shake.SetWaitTime(duration);
}