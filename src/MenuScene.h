#pragma once

#include <graphics.h>

#include <iostream>

#include "Global.h"

#include "Scene.h"
#include "SceneManager.h"

#include "Atlas.h"
#include "Animation.h"

#include "Camera.h"
#include "Timer.h"

extern IMAGE imgMenuBackground;

extern SceneManager sceneManager;

class MenuScene : public Scene
{
private:

public:
	MenuScene();
	~MenuScene();

	void Enter();
	void Input(ExMessage& msg);
	void Update(int& delta);
	void Draw(Camera& camera);
	void Exit();
};