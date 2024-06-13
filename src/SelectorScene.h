#pragma once

#include "SceneManager.h"

#include "Animation.h"

#include "Peashooter.h"
#include "Sunflower.h"
#include "Player_id.h"

#include "PutImageAlpha.h"
#include "Global.h"

extern IMAGE img_selector_scene_background;
extern IMAGE img_vs;
extern IMAGE img_tip;

extern IMAGE img_gravestone_left;
extern IMAGE img_gravestone_right;

extern IMAGE img_1p;
extern IMAGE img_2p;
extern IMAGE img_1p_desc;
extern IMAGE img_2p_desc;

extern IMAGE img_1p_selector_scene_btn_idle_left;
extern IMAGE img_1p_selector_scene_btn_idle_Right;
extern IMAGE img_2p_selector_scene_btn_idle_Left;
extern IMAGE img_2p_selector_scene_btn_idle_Right;

extern IMAGE img_1p_selector_scene_btn_down_Left;
extern IMAGE img_1p_selector_scene_btn_down_Right;
extern IMAGE img_2p_selector_scene_btn_down_Left;
extern IMAGE img_2p_selector_scene_btn_down_Right;

extern IMAGE img_peashooter_selector_scene_background_left;
extern IMAGE img_peashooter_selector_scene_background_Right;
extern IMAGE img_sunflower_selector_scene_background_left;
extern IMAGE img_sunflower_selector_scene_background_Right;

extern Atlas atlas_peashooter_idle_left;
extern Atlas atlas_peashooter_idle_right;
extern Atlas atlas_sunflower_idle_left;
extern Atlas atlas_sunflower_idle_right;

// no use
extern IMAGE img_avatar_peashooter;
extern IMAGE img_avatar_sunflower;


extern SceneManager scene_manager;

extern Player* player_1;
extern Player* player_2;

class SelectorScene : public Scene
{
public:
	SelectorScene() = default;
	~SelectorScene() = default;
private:
	enum class PlayerType
	{
		Peashooter = 0,
		Sunflower,
		Invalid
	};
private:
	POINT img_vs_position = { 0 };
	POINT img_tip_position = { 0 };

	POINT img_1pGravestonePos = { 0 };
	POINT img_2pGravestonePos = { 0 };

	POINT img_1pPos = { 0 };
	POINT img_2pPos  = { 0 };
	POINT img_1p_descPos = { 0 };
	POINT img_2p_descPos = { 0 };

	POINT btn1PSelectorLeft = { 0 };
	POINT btn1PSelectorRight = { 0 };
	POINT btn2PSelectorLeft = { 0 };
	POINT btn2PSelectorRight = { 0 };

	POINT img_1pNamePos = { 0 };
	POINT img_2pNamePos = { 0 };

	POINT animation1PPos = { 0 };
	POINT animation2PPos = { 0 };

	int selector_background_scorll_offset_x = 0;

	bool btnplus = true;
	int btn_offset = 0;

	bool is_btn_1P_left_down = false;
	bool is_btn_1P_right_down = false;
	bool is_btn_2P_left_down = false;
	bool is_btn_2P_right_down = false;
private:
	// Animation
	Animation animation_peashooter_left;
	Animation animation_peashooter_right;
	Animation animation_sunflower_left;
	Animation animation_sunflower_right;

	PlayerType player_type_1 = PlayerType::Peashooter;
	PlayerType player_type_2 = PlayerType::Sunflower;

	LPCTSTR str_peashooter_name = _T("Peashooter");
	LPCTSTR str_sunflower_name = _T("Sunflower");
public:
	// Default
	void Enter();
	void Input(ExMessage& msg);
	void Update(int& delta);
	void Draw(Camera& camera);
	void Exit();

	void OuttextxyShaded(int x, int y, LPCTSTR str);
};