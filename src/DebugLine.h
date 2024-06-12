#pragma once

#include <graphics.h>

#include "Camera.h"

class Debug
{
public:
	Debug() = default;
	~Debug() = default;
private:

};

inline void DebugLine(Camera& camera, int x1, int y1, int x2, int y2)
{
	Vector2 pos_camera = camera.GetPosition();
	line(x1 - pos_camera.x, y1 - pos_camera.y, x2 - pos_camera.x, y2 - pos_camera.y);
}