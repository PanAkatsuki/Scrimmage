#pragma once

#include <functional>

#include "Atlas.h"

#include "Util.h"

class Animation
{
public:
	Animation() = default;
	~Animation() = default;
private:
	int timer = 0;
	int interval = 0;
	int idxFrame = 0;
	bool isLoop = true;
	Atlas* atlas = nullptr;
	std::function<void()> callBack = nullptr;
public:
	void Reset();

	void SetAtlas(Atlas* atlasNew);
	void SetLoop(bool flag);
	void SetInterval(int ms);
	int GetIdxFrame() const;
	IMAGE* GetFrame() const;
	bool CheckFinished();
	void Update(int delta);
	void Draw(Camera& camera, int x, int y) const;
	void SetCallBack(std::function<void()> callBack);
};
