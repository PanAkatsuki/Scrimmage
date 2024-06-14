#pragma once

#include <vector>

#include "SceneManager.h"

#include "Platform.h"
#include "Player.h"

extern IMAGE img_sky;
extern IMAGE img_hills;
extern IMAGE img_platform_large;
extern IMAGE img_platform_small;

extern Camera camera;
extern std::vector<Platform> platform_list;
extern std::vector<Bullet*> bullet_list;

extern SceneManager scene_manager;

extern Player* player_1;
extern Player* player_2;

class GameScene : public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;
private:
	POINT img_sky_position = { 0 };
	POINT img_hills_position = { 0 };
public:
	// Default
	void Enter();
	void Input(ExMessage& msg);
	void Update(int& delta);
	void Draw(Camera& camera);
	void Exit();
};