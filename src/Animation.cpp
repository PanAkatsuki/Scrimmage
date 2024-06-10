#include "Animation.h"

void Animation::Reset()
{
	// Default
	timer = 0;
	interval = 0;
	idxFrame = 0;
	isLoop = true;
	atlas = nullptr;
}
void Animation::SetAtlas(Atlas* atlasNew)
{
	Reset();
	atlas = atlasNew;
}
void Animation::SetLoop(bool flag)
{
	isLoop = flag;
}
void Animation::SetInterval(int ms)
{
	interval = ms;
}
int Animation::GetIdxFrame() const
{
	return idxFrame;
}
IMAGE* Animation::GetFrame() const
{
	return atlas->GetImage(idxFrame);
}
bool Animation::CheckFinished()
{
	if (isLoop)
	{
		return false;
	}
	if (idxFrame == atlas->GetSize() - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Animation::Update(int delta)
{
	timer += delta;
	if (timer >= interval)
	{
		idxFrame++;
		timer = 0;
		if (idxFrame >= atlas->GetSize())
		{
			idxFrame = isLoop ? 0 : atlas->GetSize() - 1;
			if (!isLoop && callBack)
			{
				callBack();
			}
		}
	}
}
void Animation::Draw(Camera& camera, int x, int y) const
{
	PutImageAlpha(camera, x, y, atlas->GetImage(idxFrame));
}
void Animation::SetCallBack(std::function<void()> callBack)
{
	this->callBack = callBack;
}