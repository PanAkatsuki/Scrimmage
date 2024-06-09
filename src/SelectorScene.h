#pragma once

#include "SceneManager.h"

#include "Animation.h"

#include "Peashooter.h"
#include "Sunflower.h"
#include "Player_id.h"

#include "Util.h"
#include "Global.h"

extern IMAGE imgSelectorBackground;
extern IMAGE imgVS;
extern IMAGE imgSelectorTip;

extern IMAGE imgGravestoneLeft;
extern IMAGE imgGravestoneRight;

extern IMAGE img1P;
extern IMAGE img2P;
extern IMAGE img1PDesc;
extern IMAGE img2PDesc;

extern IMAGE img1PSelectorBtnIdleLeft;
extern IMAGE img1PSelectorBtnIdleRight;
extern IMAGE img1PSelectorBtnDownLeft;
extern IMAGE img1PSelectorBtnDownRight;
extern IMAGE img2PSelectorBtnIdleLeft;
extern IMAGE img2PSelectorBtnIdleRight;
extern IMAGE img2PSelectorBtnDownLeft;
extern IMAGE img2PSelectorBtnDownRight;

extern IMAGE imgPeashooterSelectorBackgroundLeft;
extern IMAGE imgPeashooterSelectorBackgroundRight;
extern IMAGE imgSunflowerSelectorBackgroundLeft;
extern IMAGE imgSunflowerSelectorBackgroundRight;

extern Atlas atlasPeashooterIdleLeft;
extern Atlas atlasPeashooterIdleRight;
extern Atlas atlasSunflowerIdleLeft;
extern Atlas atlasSunflowerIdleRight;

extern IMAGE imgAvatarPeashooter;
extern IMAGE imgAvatarSunflower;

extern SceneManager sceneManager;

extern Player* player_1;
extern Player* player_2;

class SelectorScene : public Scene
{
public:
	SelectorScene() = default;
	~SelectorScene() = default;
private:
	enum class playerType
	{
		Peashooter = 0,
		Sunflower,
		Invalid
	};
private:
	POINT imgVSPos = { 0 };
	POINT imgTipPos = { 0 };

	POINT img1PGravestonePos = { 0 };
	POINT img2PGravestonePos = { 0 };

	POINT img1PPos = { 0 };
	POINT img2PPos  = { 0 };
	POINT img1PDescPos = { 0 };
	POINT img2PDescPos = { 0 };

	POINT btn1PSelectorLeft = { 0 };
	POINT btn1PSelectorRight = { 0 };
	POINT btn2PSelectorLeft = { 0 };
	POINT btn2PSelectorRight = { 0 };

	POINT img1PNamePos = { 0 };
	POINT img2PNamePos = { 0 };

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
	Animation animationPeashooterLeft;
	Animation animationPeashooterRight;
	Animation animationSunflowerLeft;
	Animation animationSunflowerRight;

	playerType player_type_1 = playerType::Peashooter;
	playerType player_type_2 = playerType::Sunflower;

	LPCTSTR str_peashooter_name = _T("Peashooter");
	LPCTSTR str_sunflower_name = _T("Sunflower");
public:
	void Enter();
	void Input(ExMessage& msg);
	void Update(int& delta);
	void Draw(Camera& camera);
	void Exit();

	void OuttextxyShaded(int x, int y, LPCTSTR str);
};