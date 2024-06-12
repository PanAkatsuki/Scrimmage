#pragma once

#include <graphics.h>

#include "Camera.h"

class Scene
{
public:
	Scene() = default;
	~Scene() = default;
public:
	// Default
	virtual void Enter();
	virtual void Input(ExMessage& msg);
	virtual void Update(int& delta);
	virtual void Draw(Camera& camera);
	virtual void Exit();
};