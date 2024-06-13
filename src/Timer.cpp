#include "Timer.h"

// Default
void Timer::Update(int& delta)
{
	if (paused)
	{
		return;
	}

	passTime += delta;

	if (passTime >= waitTime)
	{
		if ((!oneShot || (oneShot && !shotted)) && callback)
		{
			callback();
		}
		shotted = true;
		passTime = 0;
	}
}

// Set
void Timer::SetWaitTime(int val)
{
	waitTime = val;
}

void Timer::SetPause(bool flag)
{
	paused = flag;
}

void Timer::SetOneShot(bool flag)
{
	oneShot = flag;
}

void Timer::SetCallback(std::function<void()> callback)
{
	this->callback = callback;
}

// Reset
void Timer::Restart()
{
	passTime = 0;
	shotted = false;
}