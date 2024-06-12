#pragma once

#include "Camera.h"

#include "PutImageAlpha.h"
#include "DebugLine.h"

extern bool is_debug;

class Platform
{
public:
	struct CollisionShape
	{
		int y = 0;
		int left = 0;
		int right = 0;
	};
public:
	Platform() = default;
	~Platform() = default;
private:

public:
	IMAGE* img = nullptr;
	POINT render_position = { 0 };
	CollisionShape shape;
public:
	void Draw(Camera& camera) const;
};