#pragma once

#include <functional>

#include "Atlas.h"

#include "PutImageAlpha.h"

class Animation
{
public:
	Animation() = default;
	~Animation() = default;
private:
	// Set
	Atlas* atlas = nullptr;
	int interval = 0;
	bool is_loop = true;
	std::function<void()> callBack = nullptr;

	// Reset
	int timer = 0;
	int idx_frame = 0;
public:
	// Default
	void Update(int& delta);
	void Draw(Camera& camera, int x, int y) const;
public:
	// Set
	void SetAtlas(Atlas* atlas);
	void SetInterval(int ms);
	void SetLoop(bool flag);
	void SetCallBack(std::function<void()> callBack);

	// Get
	int GetIdxFrame() const;
	IMAGE* GetFrame() const;
	
	// Reset
	void Reset();
	
	// Check
	bool CheckFinished();
};