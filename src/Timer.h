#pragma once

#include <functional>

class Timer
{
public:
	Timer() = default;
	~Timer() = default;
private:
	// Set
	int waitTime = 0;
	bool paused = false;
	bool oneShot = false;
	std::function<void()> callback = nullptr;

	// Reset
	int passTime = 0;
	bool shotted = false;
private:
	
public:
	// Default
	void Update(int& delta);
public:
	// Set
	void SetWaitTime(int val);
	void SetPause(bool flag);
	void SetOneShot(bool flag);
	void SetCallback(std::function<void()> callback);

	// Restart
	void Restart();
};