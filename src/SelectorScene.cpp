#include "SelectorScene.h"

void SelectorScene::Enter()
{
	animationPeashooterLeft.SetAtlas(&atlasPeashooterIdleLeft);
	animationPeashooterRight.SetAtlas(&atlasPeashooterIdleRight);
	animationSunflowerLeft.SetAtlas(&atlasSunflowerIdleLeft);
	animationSunflowerRight.SetAtlas(&atlasSunflowerIdleRight);

	animationPeashooterLeft.SetInterval(6);
	animationPeashooterRight.SetInterval(6);
	animationSunflowerLeft.SetInterval(6);
	animationSunflowerRight.SetInterval(6);

	static const int OFFSET_X = 50;

	imgVSPos.x = (getwidth() - imgVS.getwidth()) / 2;
	imgVSPos.y = (getheight() - imgVS.getheight()) / 2;

	imgTipPos.x = (getwidth() - imgSelectorTip.getwidth()) / 2;
	imgTipPos.y = getheight() - 125;

	img1PPos.x = (getwidth() / 2 - img1P.getwidth()) / 2 - OFFSET_X;
	img1PPos.y = 35;
	img2PPos.x = getwidth() / 2 + (getwidth() / 2 - img2P.getwidth()) / 2 + OFFSET_X;
	img2PPos.y = img1PPos.y;

	img1PDescPos.x = (getwidth() / 2 - img1PDesc.getwidth()) / 2 - OFFSET_X;
	img1PDescPos.y = getheight() - 150;
	img2PDescPos.x = getwidth() / 2 + (getwidth() / 2 - img2PDesc.getwidth()) / 2 + OFFSET_X;
	img2PDescPos.y = img1PDescPos.y;

	img1PGravestonePos.x = (getwidth() / 2 - imgGravestoneRight.getwidth()) / 2 - OFFSET_X;
	img1PGravestonePos.y = img1PPos.y + img1P.getheight() + 35;
	img2PGravestonePos.x = getwidth() / 2 + (getwidth() / 2 - imgGravestoneLeft.getwidth()) / 2 + OFFSET_X;
	img2PGravestonePos.y = img1PGravestonePos.y;

	animation1PPos.x = (getwidth() / 2 - atlasPeashooterIdleRight.GetImage(0)->getheight()) / 2 - OFFSET_X;
	animation1PPos.y = img1PGravestonePos.y + 80;
	animation2PPos.x = getwidth() / 2 + (getwidth() / 2 - atlasPeashooterIdleRight.GetImage(0)->getheight()) / 2 + OFFSET_X;
	animation2PPos.y = img2PGravestonePos.y + 80;

	img1PNamePos.x = animation1PPos.x + WINDOW_WIDTH / 100;
	img1PNamePos.y = animation1PPos.y + 155;
	img2PNamePos.x = animation2PPos.x + WINDOW_WIDTH / 100;
	img2PNamePos.y = animation2PPos.y + 155;

	btn1PSelectorLeft.x = img1PGravestonePos.x - img1PSelectorBtnIdleLeft.getwidth();
	btn1PSelectorLeft.y = img1PGravestonePos.y + (imgGravestoneRight.getheight() - img1PSelectorBtnIdleLeft.getheight()) / 2;
	btn1PSelectorRight.x = img1PGravestonePos.x + imgGravestoneRight.getwidth();
	btn1PSelectorRight.y = btn1PSelectorLeft.y;

	btn2PSelectorLeft.x = img2PGravestonePos.x - img2PSelectorBtnIdleLeft.getwidth();
	btn2PSelectorLeft.y = btn1PSelectorLeft.y;
	btn2PSelectorRight.x = img2PGravestonePos.x + imgGravestoneLeft.getwidth();
	btn2PSelectorRight.y = btn1PSelectorLeft.y;
}
void SelectorScene::Input(ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (msg.vkcode)
		{
		case 0x41:
			is_btn_1P_left_down = true;
			break;
		case 0x44:
			is_btn_1P_right_down = true;
			break;
		case VK_LEFT:
			is_btn_2P_left_down = true;
			break;
		case VK_RIGHT:
			is_btn_2P_right_down = true;
			break;
		default:
			break;
		}
		break;
	case WM_KEYUP:
		switch (msg.vkcode)
		{
		case 0x41:
			is_btn_1P_left_down = false;
			player_type_1 = (playerType)(((int)playerType::Invalid + (int)player_type_1 - 1) % (int)playerType::Invalid);
			mciSendStringW(_T("play ui_switch from 0"), NULL, 0, NULL);
			break;
		case 0x44:
			is_btn_1P_right_down = false;
			player_type_1 = (playerType)(((int)playerType::Invalid + (int)player_type_1 + 1) % (int)playerType::Invalid);
			mciSendStringW(_T("play ui_switch from 0"), NULL, 0, NULL);
			break;
		case VK_LEFT:
			is_btn_2P_left_down = false;
			player_type_2 = (playerType)(((int)playerType::Invalid + (int)player_type_2 - 1) % (int)playerType::Invalid);
			mciSendStringW(_T("play ui_switch from 0"), NULL, 0, NULL);
			break;
		case VK_RIGHT:
			is_btn_2P_right_down = false;
			player_type_2 = (playerType)(((int)playerType::Invalid + (int)player_type_2 + 1) % (int)playerType::Invalid);
			mciSendStringW(_T("play ui_switch from 0"), NULL, 0, NULL);
			break;
		case VK_RETURN:
			mciSendStringW(_T("play ui_confirm from 0"), NULL, 0, NULL);
			sceneManager.SwitchTo(SceneManager::sceneType::Game);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
void SelectorScene::Update(int& delta)
{
	animationPeashooterLeft.Update(delta);
	animationPeashooterRight.Update(delta);
	animationSunflowerLeft.Update(delta);
	animationSunflowerRight.Update(delta);

	selector_background_scorll_offset_x += 5;
	if (selector_background_scorll_offset_x >= imgPeashooterSelectorBackgroundLeft.getwidth())
	{
		selector_background_scorll_offset_x = 0;
	}

	// dynamic btn update
	btnplus ? btn_offset += 400 : btn_offset -= 400;

	if (btn_offset / WINDOW_WIDTH >= 10)
	{
		btnplus = false;
	}
	else if (btn_offset / WINDOW_WIDTH <= 0)
	{
		btnplus = true;
	}
	//
}
void SelectorScene::Draw(Camera& camera)
{
	IMAGE* p_p1_selector_background = nullptr;
	IMAGE* p_p2_selector_background = nullptr;

	switch (player_type_1)
	{
	case SelectorScene::playerType::Peashooter:
		p_p1_selector_background = &imgPeashooterSelectorBackgroundRight;
		break;
	case SelectorScene::playerType::Sunflower:
		p_p1_selector_background = &imgSunflowerSelectorBackgroundRight;
		break;
	default:
		p_p1_selector_background = nullptr;
		break;
	}
	switch (player_type_2)
	{
	case SelectorScene::playerType::Peashooter:
		p_p2_selector_background = &imgPeashooterSelectorBackgroundLeft;
		break;
	case SelectorScene::playerType::Sunflower:
		p_p2_selector_background = &imgSunflowerSelectorBackgroundLeft;
		break;
	default:
		p_p1_selector_background = nullptr;
		break;
	}

	putimage(0, 0, &imgSelectorBackground, SRCCOPY);

	if(p_p1_selector_background && p_p2_selector_background)
	{
		PutImageAlpha(camera, selector_background_scorll_offset_x - p_p1_selector_background->getwidth(), 0, p_p1_selector_background);
		PutImageAlpha(selector_background_scorll_offset_x, 0,
			p_p1_selector_background->getwidth() - selector_background_scorll_offset_x, 0, p_p1_selector_background, 0, 0);
		PutImageAlpha(getwidth() - p_p2_selector_background->getwidth(), 0,
			p_p2_selector_background->getwidth() - selector_background_scorll_offset_x, 0, p_p2_selector_background, selector_background_scorll_offset_x, 0);
		PutImageAlpha(camera, getwidth() - selector_background_scorll_offset_x, 0, p_p2_selector_background);
	}

	PutImageAlpha(camera, imgVSPos.x, imgVSPos.y, &imgVS);
	PutImageAlpha(camera, img1PPos.x, img1PPos.y, &img1P);
	PutImageAlpha(camera, img2PPos.x, img2PPos.y, &img2P);

	PutImageAlpha(camera, img1PDescPos.x, img1PDescPos.y, &img1PDesc);
	PutImageAlpha(camera, img2PDescPos.x, img2PDescPos.y, &img2PDesc);

	PutImageAlpha(camera, img1PGravestonePos.x, img1PGravestonePos.y, &imgGravestoneLeft);
	PutImageAlpha(camera, img2PGravestonePos.x, img2PGravestonePos.y, &imgGravestoneRight);

	PutImageAlpha(camera, imgTipPos.x, imgTipPos.y, &imgSelectorTip);

	PutImageAlpha(camera, btn1PSelectorLeft.x - btn_offset / WINDOW_WIDTH, btn1PSelectorLeft.y, is_btn_1P_left_down ? &img1PSelectorBtnDownLeft : &img1PSelectorBtnIdleLeft);
	PutImageAlpha(camera, btn1PSelectorRight.x + btn_offset / WINDOW_WIDTH, btn1PSelectorRight.y, is_btn_1P_right_down ? &img1PSelectorBtnDownRight : &img1PSelectorBtnIdleRight);
	PutImageAlpha(camera, btn2PSelectorLeft.x - btn_offset / WINDOW_WIDTH, btn2PSelectorLeft.y, is_btn_2P_left_down ? &img2PSelectorBtnDownLeft : &img2PSelectorBtnIdleLeft);
	PutImageAlpha(camera, btn2PSelectorRight.x + btn_offset / WINDOW_WIDTH, btn2PSelectorRight.y, is_btn_2P_right_down ? &img2PSelectorBtnDownRight : &img2PSelectorBtnIdleRight);
	
	switch (player_type_1)
	{
	case playerType::Peashooter:
		animationPeashooterRight.Draw(camera, animation1PPos.x, animation1PPos.y);
		img1PNamePos.x = img1PGravestonePos.x + ((imgGravestoneRight.getwidth() - textwidth(str_peashooter_name)) / 2);
		OuttextxyShaded(img1PNamePos.x, img1PNamePos.y, str_peashooter_name);
		break;
	case playerType::Sunflower:
		animationSunflowerRight.Draw(camera, animation1PPos.x, animation1PPos.y);
		img1PNamePos.x = img1PGravestonePos.x + ((imgGravestoneRight.getwidth() - textwidth(str_sunflower_name)) / 2);
		OuttextxyShaded(img1PNamePos.x, img1PNamePos.y, str_sunflower_name);
		break;
	}
	switch (player_type_2)
	{
	case playerType::Peashooter:
		animationPeashooterLeft.Draw(camera, animation2PPos.x, animation2PPos.y);
		img2PNamePos.x = img2PGravestonePos.x + ((imgGravestoneLeft.getwidth() - textwidth(str_peashooter_name)) / 2);
		OuttextxyShaded(img2PNamePos.x, img2PNamePos.y, str_peashooter_name);
		break;
	case playerType::Sunflower:
		animationSunflowerLeft.Draw(camera, animation2PPos.x, animation2PPos.y);
		img2PNamePos.x = img2PGravestonePos.x + ((imgGravestoneLeft.getwidth() - textwidth(str_sunflower_name)) / 2);
		OuttextxyShaded(img2PNamePos.x, img2PNamePos.y, str_sunflower_name);
		break;
	}
}
void SelectorScene::Exit()
{
	switch (player_type_1)
	{
	case SelectorScene::playerType::Peashooter:
		player_1 = new Peashooter();
		break;
	case SelectorScene::playerType::Sunflower:
		player_1 = new Sunflower();
		break;
	}
	player_1->SetID(PlayerID::P1);
	switch (player_type_2)
	{
	case SelectorScene::playerType::Peashooter:
		player_2 = new Peashooter();
		break;
	case SelectorScene::playerType::Sunflower:
		player_2 = new Sunflower();
		break;
	}
	player_2->SetID(PlayerID::P2);
}

void SelectorScene::OuttextxyShaded(int x, int y, LPCTSTR str)
{
	settextcolor(RGB(45, 45, 45));
	outtextxy(x + 2, y + 2, str);
	settextcolor(RGB(255, 255, 255));
	outtextxy(x, y, str);
}