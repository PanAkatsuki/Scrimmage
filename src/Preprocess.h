#pragma once

#include <vector>

#include "SceneManager.h"
#include "Atlas.h"

#include "Platform.h"
#include "Player.h"

IMAGE imgMenuBackground;

IMAGE imgVS;
IMAGE img1P;
IMAGE img2P;
IMAGE img1PDesc;
IMAGE img2PDesc;
IMAGE imgGravestoneLeft;
IMAGE imgGravestoneRight;
IMAGE imgSelectorTip;
IMAGE imgSelectorBackground;
IMAGE img1PSelectorBtnIdleLeft;
IMAGE img1PSelectorBtnIdleRight;
IMAGE img1PSelectorBtnDownLeft;
IMAGE img1PSelectorBtnDownRight;
IMAGE img2PSelectorBtnIdleLeft;
IMAGE img2PSelectorBtnIdleRight;
IMAGE img2PSelectorBtnDownLeft;
IMAGE img2PSelectorBtnDownRight;
IMAGE imgPeashooterSelectorBackgroundLeft;
IMAGE imgPeashooterSelectorBackgroundRight;
IMAGE imgSunflowerSelectorBackgroundLeft;
IMAGE imgSunflowerSelectorBackgroundRight;

IMAGE imgSky;
IMAGE imgHills;
IMAGE imgPlatformLarge;
IMAGE imgPlatformSmall;

IMAGE img1PCursor;
IMAGE img2PCursor;

Atlas atlasPeashooterIdleLeft;
Atlas atlasPeashooterIdleRight;
Atlas atlasPeashooterRunLeft;
Atlas atlasPeashooterRunRight;
Atlas atlasPeashooterAttackEXLeft;
Atlas atlasPeashooterAttackEXRight;
Atlas atlasPeashooterDieLeft;
Atlas atlasPeashooterDieRight;

Atlas atlasSunflowerIdleLeft;
Atlas atlasSunflowerIdleRight;
Atlas atlasSunflowerRunLeft;
Atlas atlasSunflowerRunRight;
Atlas atlasSunflowerAttackEXLeft;
Atlas atlasSunflowerAttackEXRight;
Atlas atlasSunflowerDieLeft;
Atlas atlasSunflowerDieRight;

IMAGE imgPea;
Atlas atlasPeaBreak;
Atlas atlasSun;
Atlas atlasSunExplode;
Atlas atlasSunEX;
Atlas atlasSunEXExplode;
Atlas atlasSunText;

Atlas atlasRunEffect;
Atlas atlasJumpEffect;
Atlas atlasLandEffect;

IMAGE img1PWinner;
IMAGE img2PWinner;
IMAGE imgWinnerBar;

IMAGE imgAvatarPeashooter;
IMAGE imgAvatarSunflower;


Scene* menuScene = nullptr;
Scene* gameScene = nullptr;
Scene* selectorScene = nullptr;

Camera camera;
SceneManager sceneManager;

std::vector<Platform> platform_list;

Player* player_1 = nullptr;
Player* player_2 = nullptr;

inline void FlipAtlas(Atlas& src, Atlas& dst)
{
	dst.Clear();
	for (int i = 0; i < src.GetSize(); i++)
	{
		IMAGE imgFlipped;
		FlipImage(src.GetImage(i), &imgFlipped);
		dst.AddImage(imgFlipped);
	}
}

inline void LoadGameResource()
{
	AddFontResourceEx(_T("resources/IPix.ttf"), FR_PRIVATE, NULL);

	loadimage(&imgMenuBackground, _T("resources/menu_background.png"));

	loadimage(&imgVS, _T("resources/VS.png"));
	loadimage(&img1P, _T("resources/1P.png"));
	loadimage(&img2P, _T("resources/2P.png"));
	loadimage(&img1PDesc, _T("resources/1P_desc.png"));
	loadimage(&img2PDesc, _T("resources/2P_desc.png"));
	loadimage(&imgGravestoneRight, _T("resources/gravestone.png"));
	FlipImage(&imgGravestoneRight, &imgGravestoneLeft);
	loadimage(&imgSelectorTip, _T("resources/selector_tip.png"));
	loadimage(&imgSelectorBackground, _T("resources/selector_background.png"));
	loadimage(&img1PSelectorBtnIdleRight, _T("resources/1P_selector_btn_idle.png"));
	FlipImage(&img1PSelectorBtnIdleRight, &img1PSelectorBtnIdleLeft);
	loadimage(&img1PSelectorBtnDownRight, _T("resources/1P_selector_btn_down.png"));
	FlipImage(&img1PSelectorBtnDownRight, &img1PSelectorBtnDownLeft);
	loadimage(&img2PSelectorBtnIdleRight, _T("resources/2P_selector_btn_idle.png"));
	FlipImage(&img2PSelectorBtnIdleRight, &img2PSelectorBtnIdleLeft);
	loadimage(&img2PSelectorBtnDownRight, _T("resources/2P_selector_btn_down.png"));
	FlipImage(&img2PSelectorBtnDownRight, &img2PSelectorBtnDownLeft);
	loadimage(&imgPeashooterSelectorBackgroundRight, _T("resources/peashooter_selector_background.png"));
	FlipImage(&imgPeashooterSelectorBackgroundRight, &imgPeashooterSelectorBackgroundLeft);
	loadimage(&imgSunflowerSelectorBackgroundRight, _T("resources/sunflower_selector_background.png"));
	FlipImage(&imgSunflowerSelectorBackgroundRight, &imgSunflowerSelectorBackgroundLeft);

	loadimage(&imgSky, _T("resources/sky.png"));
	loadimage(&imgHills, _T("resources/hills.png"));
	loadimage(&imgPlatformLarge, _T("resources/platform_large.png"));
	loadimage(&imgPlatformSmall, _T("resources/platform_small.png"));

	loadimage(&img1PCursor, _T("resources/1P_cursor.png"));
	loadimage(&img2PCursor, _T("resources/2P_cursor.png"));

	atlasPeashooterIdleRight.LoadFromFile(_T("resources/peashooter_idle_%d.png"), 9);
	FlipAtlas(atlasPeashooterIdleRight, atlasPeashooterIdleLeft);
	atlasPeashooterRunRight.LoadFromFile(_T("resources/peashooter_run_%d.png"), 5);
	FlipAtlas(atlasPeashooterRunRight, atlasPeashooterRunLeft);
	atlasPeashooterAttackEXRight.LoadFromFile(_T("resources/peashooter_attack_ex_%d.png"), 3);
	FlipAtlas(atlasPeashooterAttackEXRight, atlasPeashooterAttackEXLeft);
	atlasPeashooterDieRight.LoadFromFile(_T("resources/peashooter_die_%d.png"), 4);
	FlipAtlas(atlasPeashooterDieRight, atlasPeashooterDieLeft);

	atlasSunflowerIdleRight.LoadFromFile(_T("resources/Sunflower_idle_%d.png"), 8);
	FlipAtlas(atlasSunflowerIdleRight, atlasSunflowerIdleLeft);
	atlasSunflowerRunRight.LoadFromFile(_T("resources/Sunflower_run_%d.png"), 5);
	FlipAtlas(atlasSunflowerRunRight, atlasSunflowerRunLeft);
	atlasSunflowerAttackEXRight.LoadFromFile(_T("resources/Sunflower_attack_ex_%d.png"), 9);
	FlipAtlas(atlasSunflowerAttackEXRight, atlasSunflowerAttackEXLeft);
	atlasSunflowerDieRight.LoadFromFile(_T("resources/Sunflower_die_%d.png"), 2);
	FlipAtlas(atlasSunflowerDieRight, atlasSunflowerDieLeft);

	loadimage(&imgPea, _T("resources/pea.png"));
	atlasPeaBreak.LoadFromFile(_T("resources/pea_break_%d.png"), 3);
	atlasSun.LoadFromFile(_T("resources/sun_%d.png"), 5);
	atlasSunExplode.LoadFromFile(_T("resources/sun_explode_%d.png"), 5);
	atlasSunEX.LoadFromFile(_T("resources/sun_ex_%d.png"), 5);
	atlasSunEXExplode.LoadFromFile(_T("resources/sun_ex_explode_%d.png"), 5);
	atlasSunText.LoadFromFile(_T("resources/sun_text_%d.png"), 6);

	atlasRunEffect.LoadFromFile(_T("resources/run_effect_%d.png"), 4);
	atlasJumpEffect.LoadFromFile(_T("resources/jump_effect_%d.png"), 5);
	atlasLandEffect.LoadFromFile(_T("resources/land_effect_%d.png"), 2);

	loadimage(&img1PWinner, _T("resources/1P_winner.png"));
	loadimage(&img2PWinner, _T("resources/2P_winner.png"));
	loadimage(&imgWinnerBar, _T("resources/winnner_bar.png"));

	loadimage(&imgAvatarPeashooter, _T("resources/avatar_peashooter.png"));
	loadimage(&imgAvatarSunflower, _T("resources/avatar_sunflower.png"));

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
}