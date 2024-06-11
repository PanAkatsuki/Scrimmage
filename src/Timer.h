#pragma once

#include <functional>

class Timer
{
public:
	Timer() = default;
	~Timer() = default;
private:
	int passTime = 0;
	bool shotted = false;

	int waitTime = 0;
	bool paused = false;
	bool oneShot = false;
public:

private:
	std::function<void()> callback = nullptr;
public:
	void Restart();
	void Init();
	void SetWaitTime(int val);
	void SetOneShot(bool flag);
	void SetCallback(std::function<void()> callback);
	void Pause();
	void Resume();

	void Update(int& delta);
};