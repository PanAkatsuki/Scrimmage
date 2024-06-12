#include "Animation.h"

// Default
void Animation::Update(int& delta)
{
	timer += delta;
	if (timer >= interval)
	{
		idx_frame++;
		timer = 0;
		if (idx_frame >= atlas->GetSize())
		{
			idx_frame = is_loop ? 0 : atlas->GetSize() - 1;
			if (!is_loop && callBack)
			{
				callBack();
			}
		}
	}
}

void Animation::Draw(Camera& camera, int x, int y) const
{
	PutImageAlpha(camera, x, y, atlas->GetImage(idx_frame));
}

// Set
void Animation::SetAtlas(Atlas* atlas)
{
	Reset();
	this->atlas = atlas;
}

void Animation::SetLoop(bool flag)
{
	is_loop = flag;
}

void Animation::SetInterval(int ms)
{
	interval = ms;
}

void Animation::SetCallBack(std::function<void()> callBack)
{
	this->callBack = callBack;
}

// Get
int Animation::GetIdxFrame() const
{
	return idx_frame;
}

IMAGE* Animation::GetFrame() const
{
	return atlas->GetImage(idx_frame);
}

// Reset
void Animation::Reset()
{
	timer = 0;
	idx_frame = 0;
}

// Check
bool Animation::CheckFinished()
{
	if (is_loop)
	{
		return false;
	}
	if (idx_frame == atlas->GetSize() - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}