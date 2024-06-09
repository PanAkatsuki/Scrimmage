#pragma once

#include <graphics.h>

#include "Camera.h"

class Scene
{
private:

public:
	Scene();
	~Scene();

	virtual void Enter() {};
	virtual void Input(ExMessage& msg) {};
	virtual void Update(int& delta) {};
	virtual void Draw(Camera& camera) {};
	virtual void Exit() {};
};