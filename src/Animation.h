#pragma once

#include <functional>

#include "Atlas.h"

#include "Util.h"

class Animation
{
public:
	Animation();
	~Animation();
private:
	int timer;
	int interval;
	int idxFrame;
	bool isLoop;
	Atlas* atlas;

	std::function<void()> callBack;
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
