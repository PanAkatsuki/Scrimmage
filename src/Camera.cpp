#include "Camera.h"

// Constructor
Camera::Camera()
{
	timer_shake.SetOneShot(true);
	timer_shake.SetCallback(
		[&]()
		{
			// DON'T OPERATE TIMER IN TIMER'S CALLBACK!!!!!
			// Reset camera
			SetPosition(0, 0);
			is_shaking = false;
			shaking_strength = 0;
		}
	);
}

// Default
void Camera::Update(int& delta)
{
	if (is_shaking)
	{
		timer_shake.Update(delta);
		position.x = (-50 + rand() % 100) / 10 * shaking_strength;
		position.y = (-50 + rand() % 100) / 10 * shaking_strength;
	}
}

// Set
void Camera::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

// Get
Vector2 Camera::GetPosition() const
{
	return position;
}

// Shake
void Camera::Shake(int strength, int duration)
{
	// Restart timer
	timer_shake.Restart();

	// Set is_shaking
	is_shaking = true;

	// Set strength and duration
	shaking_strength = strength;
	timer_shake.SetWaitTime(duration);
}