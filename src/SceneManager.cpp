#include "SceneManager.h"

// Default
void SceneManager::Input(ExMessage& msg)
{
	current_scene->Input(msg);
}

void SceneManager::Update(int delta)
{
	current_scene->Update(delta);
}

void SceneManager::Draw(Camera& camera) const
{
	current_scene->Draw(camera);
}

// Set
void SceneManager::SetCurrentScene(Scene* scene)
{
	current_scene = scene;
	current_scene->Enter();
}

// Switch
void SceneManager::SwitchTo(SceneManager::SceneType type)
{
	current_scene->Exit();
	switch (type)
	{
	case SceneManager::SceneType::Menu:
		current_scene = menu_scene;
		break;
	case SceneManager::SceneType::Game:
		current_scene = game_scene;
		break;
	case SceneManager::SceneType::Selector:
		current_scene = selector_scene;
		break;
	default:
		break;
	}
	current_scene->Enter();
}