#pragma once

#include "Scene.h"

extern Scene* menuScene;
extern Scene* gameScene;
extern Scene* selectorScene;

class SceneManager
{
public:
	enum class sceneType
	{
		Menu,
		Game,
		Selector
	};
private:
	Scene* currentScene;
public:
	SceneManager();
	~SceneManager();

	void Input(ExMessage& msg);
	void Update(int delta);
	void Draw(Camera& camera) const;

	void SetCurrentScene(Scene* scene);
	void SwitchTo(SceneManager::sceneType type);
};