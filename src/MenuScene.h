#pragma once

#include <graphics.h>

#include "SceneManager.h"

extern IMAGE imgMenuBackground;

extern SceneManager scene_manager;

class MenuScene : public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;
public:
	// Default
	void Enter();
	void Input(ExMessage& msg);
	void Update(int& delta);
	void Draw(Camera& camera);
	void Exit();
};