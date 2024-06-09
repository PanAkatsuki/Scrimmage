#include "SceneManager.h"

SceneManager::SceneManager()
{
	currentScene = nullptr;
}
SceneManager::~SceneManager()
{

}

void SceneManager::Input(ExMessage& msg)
{
	currentScene->Input(msg);
}
void SceneManager::Update(int delta)
{
	currentScene->Update(delta);
}
void SceneManager::Draw(Camera& camera) const
{
	currentScene->Draw(camera);
}

void SceneManager::SetCurrentScene(Scene* scene)
{
	currentScene = scene;
	currentScene->Enter();
}
void SceneManager::SwitchTo(SceneManager::sceneType type)
{
	currentScene->Exit();
	switch (type)
	{
	case SceneManager::sceneType::Menu:
		currentScene = menuScene;
		break;
	case SceneManager::sceneType::Game:
		currentScene = gameScene;
		break;
	case SceneManager::sceneType::Selector:
		currentScene = selectorScene;
		break;
	default:
		break;
	}
	currentScene->Enter();
}

