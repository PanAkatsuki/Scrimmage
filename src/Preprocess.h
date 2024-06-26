#pragma once

#include <vector>

#include "SceneManager.h"

#include "Platform.h"
#include "Player.h"

#include "FlipAtlas.h"

IMAGE img_menu_background;

IMAGE img_vs;
IMAGE img_1p;
IMAGE img_2p;
IMAGE img_1p_desc;
IMAGE img_2p_desc;
IMAGE img_gravestone_left;
IMAGE img_gravestone_right;
IMAGE img_tip;
IMAGE img_selector_scene_background;
IMAGE img_1p_selector_scene_btn_idle_left;
IMAGE img_1p_selector_scene_btn_idle_Right;
IMAGE img_1p_selector_scene_btn_down_Left;
IMAGE img_1p_selector_scene_btn_down_Right;
IMAGE img_2p_selector_scene_btn_idle_Left;
IMAGE img_2p_selector_scene_btn_idle_Right;
IMAGE img_2p_selector_scene_btn_down_Left;
IMAGE img_2p_selector_scene_btn_down_Right;
IMAGE img_peashooter_selector_scene_background_left;
IMAGE img_peashooter_selector_scene_background_Right;
IMAGE img_sunflower_selector_scene_background_left;
IMAGE img_sunflower_selector_scene_background_Right;

IMAGE img_sky;
IMAGE img_hills;
IMAGE img_platform_large;
IMAGE img_platform_small;

IMAGE img_1p_cursor;
IMAGE img_2p_cursor;

Atlas atlas_peashooter_idle_left;
Atlas atlas_peashooter_idle_right;
Atlas atlas_peashooter_run_left;
Atlas atlas_peashooter_run_right;
Atlas atlas_peashooter_attack_ex_left;
Atlas atlas_peashooter_attack_ex_right;
Atlas atlas_peashooter_die_left;
Atlas atlas_peashooter_die_right;

Atlas atlas_sunflower_idle_left;
Atlas atlas_sunflower_idle_right;
Atlas atlas_sunflower_run_left;
Atlas atlas_sunflower_run_right;
Atlas atlas_sunflower_attack_ex_left;
Atlas atlas_sunflower_attack_ex_right;
Atlas atlas_sunflower_die_left;
Atlas atlas_sunflower_die_right;

IMAGE img_pea;
Atlas atlas_pea_break;
Atlas atlas_sun;
Atlas atlas_sun_explode;
Atlas atlas_sun_ex;
Atlas atlas_sun_ex_explode;
Atlas atlas_sun_text;

Atlas atlas_run_effect;
Atlas atlas_jump_effect;
Atlas atlas_land_effect;

IMAGE img_1p_winner;
IMAGE img_2p_winner;
IMAGE img_winner_bar;

IMAGE img_avatar_peashooter;
IMAGE img_avatar_sunflower;


Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* selector_scene = nullptr;

Camera camera;
SceneManager scene_manager;

std::vector<Platform> platform_list;
std::vector<Bullet*> bullet_list;

Player* player_1 = nullptr;
Player* player_2 = nullptr;

inline void LoadGameResource()
{
	AddFontResourceEx(_T("resources/IPix.ttf"), FR_PRIVATE, NULL);

	loadimage(&img_menu_background, _T("resources/menu_background.png"));

	loadimage(&img_vs, _T("resources/VS.png"));
	loadimage(&img_1p, _T("resources/1P.png"));
	loadimage(&img_2p, _T("resources/2P.png"));
	loadimage(&img_1p_desc, _T("resources/1P_desc.png"));
	loadimage(&img_2p_desc, _T("resources/2P_desc.png"));
	loadimage(&img_gravestone_right, _T("resources/gravestone.png"));
	FlipImage(&img_gravestone_right, &img_gravestone_left);
	loadimage(&img_tip, _T("resources/selector_tip.png"));
	loadimage(&img_selector_scene_background, _T("resources/selector_background.png"));
	loadimage(&img_1p_selector_scene_btn_idle_Right, _T("resources/1P_selector_btn_idle.png"));
	FlipImage(&img_1p_selector_scene_btn_idle_Right, &img_1p_selector_scene_btn_idle_left);
	loadimage(&img_1p_selector_scene_btn_down_Right, _T("resources/1P_selector_btn_down.png"));
	FlipImage(&img_1p_selector_scene_btn_down_Right, &img_1p_selector_scene_btn_down_Left);
	loadimage(&img_2p_selector_scene_btn_idle_Right, _T("resources/2P_selector_btn_idle.png"));
	FlipImage(&img_2p_selector_scene_btn_idle_Right, &img_2p_selector_scene_btn_idle_Left);
	loadimage(&img_2p_selector_scene_btn_down_Right, _T("resources/2P_selector_btn_down.png"));
	FlipImage(&img_2p_selector_scene_btn_down_Right, &img_2p_selector_scene_btn_down_Left);
	loadimage(&img_peashooter_selector_scene_background_Right, _T("resources/peashooter_selector_background.png"));
	FlipImage(&img_peashooter_selector_scene_background_Right, &img_peashooter_selector_scene_background_left);
	loadimage(&img_sunflower_selector_scene_background_Right, _T("resources/sunflower_selector_background.png"));
	FlipImage(&img_sunflower_selector_scene_background_Right, &img_sunflower_selector_scene_background_left);

	loadimage(&img_sky, _T("resources/sky.png"));
	loadimage(&img_hills, _T("resources/hills.png"));
	loadimage(&img_platform_large, _T("resources/platform_large.png"));
	loadimage(&img_platform_small, _T("resources/platform_small.png"));

	loadimage(&img_1p_cursor, _T("resources/1P_cursor.png"));
	loadimage(&img_2p_cursor, _T("resources/2P_cursor.png"));

	atlas_peashooter_idle_right.LoadFromFile(_T("resources/peashooter_idle_%d.png"), 9);
	FlipAtlas(atlas_peashooter_idle_right, atlas_peashooter_idle_left);
	atlas_peashooter_run_right.LoadFromFile(_T("resources/peashooter_run_%d.png"), 5);
	FlipAtlas(atlas_peashooter_run_right, atlas_peashooter_run_left);
	atlas_peashooter_attack_ex_right.LoadFromFile(_T("resources/peashooter_attack_ex_%d.png"), 3);
	FlipAtlas(atlas_peashooter_attack_ex_right, atlas_peashooter_attack_ex_left);
	atlas_peashooter_die_right.LoadFromFile(_T("resources/peashooter_die_%d.png"), 4);
	FlipAtlas(atlas_peashooter_die_right, atlas_peashooter_die_left);

	atlas_sunflower_idle_right.LoadFromFile(_T("resources/Sunflower_idle_%d.png"), 8);
	FlipAtlas(atlas_sunflower_idle_right, atlas_sunflower_idle_left);
	atlas_sunflower_run_right.LoadFromFile(_T("resources/Sunflower_run_%d.png"), 5);
	FlipAtlas(atlas_sunflower_run_right, atlas_sunflower_run_left);
	atlas_sunflower_attack_ex_right.LoadFromFile(_T("resources/Sunflower_attack_ex_%d.png"), 9);
	FlipAtlas(atlas_sunflower_attack_ex_right, atlas_sunflower_attack_ex_left);
	atlas_sunflower_die_right.LoadFromFile(_T("resources/Sunflower_die_%d.png"), 2);
	FlipAtlas(atlas_sunflower_die_right, atlas_sunflower_die_left);

	loadimage(&img_pea, _T("resources/pea.png"));
	atlas_pea_break.LoadFromFile(_T("resources/pea_break_%d.png"), 3);
	atlas_sun.LoadFromFile(_T("resources/sun_%d.png"), 5);
	atlas_sun_explode.LoadFromFile(_T("resources/sun_explode_%d.png"), 5);
	atlas_sun_ex.LoadFromFile(_T("resources/sun_ex_%d.png"), 5);
	atlas_sun_ex_explode.LoadFromFile(_T("resources/sun_ex_explode_%d.png"), 5);
	atlas_sun_text.LoadFromFile(_T("resources/sun_text_%d.png"), 6);

	atlas_run_effect.LoadFromFile(_T("resources/run_effect_%d.png"), 4);
	atlas_jump_effect.LoadFromFile(_T("resources/jump_effect_%d.png"), 5);
	atlas_land_effect.LoadFromFile(_T("resources/land_effect_%d.png"), 2);

	loadimage(&img_1p_winner, _T("resources/1P_winner.png"));
	loadimage(&img_2p_winner, _T("resources/2P_winner.png"));
	loadimage(&img_winner_bar, _T("resources/winnner_bar.png"));

	loadimage(&img_avatar_peashooter, _T("resources/avatar_peashooter.png"));
	loadimage(&img_avatar_sunflower, _T("resources/avatar_sunflower.png"));

	mciSendStringW(_T("open resources/bgm_game.mp3 alias bgm_game"), NULL, 0, NULL);
	mciSendStringW(_T("open resources/bgm_menu.mp3 alias bgm_menu"), NULL, 0, NULL);
				 
	mciSendStringW(_T("open resources/pea_break_1.mp3 alias pea_break_1"), NULL, 0, NULL);
	mciSendStringW(_T("open resources/pea_break_2.mp3 alias pea_break_2"), NULL, 0, NULL);
	mciSendStringW(_T("open resources/pea_break_3.mp3 alias pea_break_3"), NULL, 0, NULL);
	mciSendStringW(_T("open resources/pea_shoot_1.mp3 alias pea_shoot_1"), NULL, 0, NULL);
	mciSendStringW(_T("open resources/pea_shoot_2.mp3 alias pea_shoot_2"), NULL, 0, NULL);
	mciSendStringW(_T("open resources/pea_shoot_ex.mp3 alias pea_shoot_ex"), NULL, 0, NULL);
				 
	mciSendStringW(_T("open resources/sun_explode.mp3 alias sun_explode"), NULL, 0, NULL);
	mciSendStringW(_T("open resources/sun_explode_ex.mp3 alias sun_explode_ex"), NULL, 0, NULL);
	mciSendStringW(_T("open resources/sun_text.mp3 alias sun_text"), NULL, 0, NULL);
				 
	mciSendStringW(_T("open resources/ui_confirm.wav alias ui_confirm"), NULL, 0, NULL);
	mciSendStringW(_T("open resources/ui_switch.wav alias ui_switch"), NULL, 0, NULL);
	mciSendStringW(_T("open resources/ui_win.wav alias ui_win"), NULL, 0, NULL);

	mciSendStringW(_T("open resources/mp_not_enough.mp3 alias mp_not_enough"), NULL, 0, NULL);
}