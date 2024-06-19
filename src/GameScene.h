#pragma once

#include <vector>

#include "SceneManager.h"

#include "Platform.h"
#include "Player.h"
#include "StatusBar.h"

#include "Global.h"

extern IMAGE img_sky;
extern IMAGE img_hills;
extern IMAGE img_platform_large;
extern IMAGE img_platform_small;

extern IMAGE img_1p_winner;
extern IMAGE img_2p_winner;
extern IMAGE img_winner_bar;

extern Camera camera;
extern std::vector<Platform> platform_list;
extern std::vector<Bullet*> bullet_list;

extern SceneManager scene_manager;

extern Player* player_1;
extern Player* player_2;

extern IMAGE img_avatar_peashooter;
extern IMAGE img_avatar_sunflower;

class GameScene : public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;
private:
	// Background
	POINT position_img_sky = { 0, 0 };
	POINT position_img_hills = { 0, 0 };

	// Status bar
	StatusBar status_bar_p1;
	StatusBar status_bar_p2;

	// Game over
	bool is_game_over = false;

	POINT position_img_winner_bar = { 0, 0 };
	POINT position_img_winner_text = { 0, 0 };
	int position_x_img_winner_bar_dst = 0;
	int position_x_img_winner_text_dst = 0;
	Timer timer_winner_slide_in;
	const int time_winner_slide_in = 180;
	int speed_slide_in_bar = 0;
	int speed_slide_in_text = 0;
	Timer timer_winner_slide_out;
	const int time_winner_slide_out = 100;
	int speed_slide_out_bar = 0;
	int speed_slide_out_text = 0;
	bool is_slide_out_started = false;
public:
	// Default
	void Enter();
	void Input(ExMessage& msg);
	void Update(int& delta);
	void Draw(Camera& camera);
	void Exit();
};