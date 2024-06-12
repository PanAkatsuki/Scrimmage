#pragma once

#include <graphics.h>

#include "SceneManager.h"

extern IMAGE imgMenuBackground;

extern SceneManager scene_manager;

extern Camera camera;

class MenuScene : public Scene
{
private:

public:
	MenuScene() = default;
	~MenuScene() = default;

	void Enter();
	void Input(ExMessage& msg);
	void Update(int& delta);
	void Draw(Camera& camera);
	void Exit();
};