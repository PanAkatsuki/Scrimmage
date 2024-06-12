#pragma once

#include <vector>

#include "Scene.h"
#include "SceneManager.h"

#include "Platform.h"
#include "Player.h"

extern IMAGE imgSky;
extern IMAGE imgHills;
extern IMAGE imgPlatformLarge;
extern IMAGE imgPlatformSmall;

extern Camera camera;
extern std::vector<Platform> platform_list;

extern SceneManager scene_manager;

extern Player* player_1;
extern Player* player_2;

class GameScene : public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;
private:
	POINT pos_imgSky = { 0 };
	POINT pos_imgHills = { 0 };
public:
	void Enter();
	void Input(ExMessage& msg);
	void Update(int& delta);
	void Draw(Camera& camera);
	void Exit();
};