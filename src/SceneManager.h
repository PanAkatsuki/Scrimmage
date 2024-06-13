#pragma once

#include "Scene.h"

extern Scene* menu_scene;
extern Scene* selector_scene;
extern Scene* game_scene;

class SceneManager
{
public:
	SceneManager() = default;
	~SceneManager() = default;
public:
	enum class SceneType
	{
		Menu,
		Selector,
		Game
	};
private:
	Scene* current_scene = nullptr;
public:
	// Default
	void Input(ExMessage& msg);
	void Update(int delta);
	void Draw(Camera& camera) const;
public:
	// Set
	void SetCurrentScene(Scene* scene);

	// Switch
	void SwitchTo(SceneManager::SceneType type);
};