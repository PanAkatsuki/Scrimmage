#include "Timer.h"

void Timer::Restart()
{
	passTime = 0;
	shotted = false;
}
void Timer::Init()
{
	passTime = 0;
	waitTime = 0;
	paused = false;
	shotted = false;
	oneShot = false;
	callback = nullptr;
}
void Timer::SetWaitTime(int val)
{
	waitTime = val;
}
void Timer::SetOneShot(bool flag)
{
	oneShot = flag;
}
void Timer::SetCallback(std::function<void()> callback)
{
	this->callback = callback;
}
void Timer::Pause()
{
	paused = true;
}
void Timer::Resume()
{
	paused = false;
}

void Timer::Update(int& delta)
{
	if (paused)
	{
		return;
	}
	passTime += delta;
	if (passTime >= waitTime)
	{
		if (!oneShot || (oneShot && !shotted) && callback)
		{
			callback();
		}
		shotted = true;
		passTime = 0;
	}
}