#include "Camera.h"

Camera::Camera()
{
	isShaking = false;
	shakingStrength = 0;
	/*
	timerShake.SetOneShot(true);
	timerShake.SetCallback([&]()
		{
			isShaking = false;
			Reset();
		}
	);
	*/
}
Camera::~Camera()
{

}

Vector2 Camera::GetPos() const
{
	return pos;
}
void Camera::Reset()
{
	pos.x = 0;
	pos.y = 0;
}
void Camera::Update(int& delta)
{
	/*
	float deltaf = (float)delta;
	Vector2 speed;
	speed.x = -0.1f;
	speed.y = -0.0f;
	//speed.MultiVal(deltaf);
	Vector2 tmp = speed.V2MultiVal(deltaf);
	pos.PlusVec(tmp);
	*/
	timerShake.Update(delta);
	if (isShaking)
	{
		pos.x = (-50 + rand() % 100) / 50.0f * shakingStrength;
		pos.y = (-50 + rand() % 100) / 50.0f * shakingStrength;
	}
}

void Camera::Shake(float strength, int duration)
{
	isShaking = true;
	shakingStrength = strength;

	timerShake.SetWaitTime(duration);
	timerShake.Restart();
}