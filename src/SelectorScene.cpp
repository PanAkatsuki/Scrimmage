#include "SelectorScene.h"

// Default
void SelectorScene::Enter()
{
	// Set atlas
	animation_peashooter_left.SetAtlas(&atlas_peashooter_idle_left);
	animation_peashooter_right.SetAtlas(&atlas_peashooter_idle_right);
	animation_sunflower_left.SetAtlas(&atlas_sunflower_idle_left);
	animation_sunflower_right.SetAtlas(&atlas_sunflower_idle_right);

	// Set interval
	animation_peashooter_left.SetInterval(6);
	animation_peashooter_right.SetInterval(6);
	animation_sunflower_left.SetInterval(6);
	animation_sunflower_right.SetInterval(6);

	static const int OFFSET_X = 50;

	img_vs_position.x = (getwidth() - img_vs.getwidth()) / 2;
	img_vs_position.y = (getheight() - img_vs.getheight()) / 2;

	img_tip_position.x = (getwidth() - img_tip.getwidth()) / 2;
	img_tip_position.y = getheight() - 125;

	img_1p_position.x = (getwidth() / 2 - img_1p.getwidth()) / 2 - OFFSET_X;
	img_1p_position.y = 35;
	img_2p_position.x = getwidth() / 2 + (getwidth() / 2 - img_2p.getwidth()) / 2 + OFFSET_X;
	img_2p_position.y = img_1p_position.y;

	img_1p_desc_position.x = (getwidth() / 2 - img_1p_desc.getwidth()) / 2 - OFFSET_X;
	img_1p_desc_position.y = getheight() - 150;
	img_2p_desc_position.x = getwidth() / 2 + (getwidth() / 2 - img_2p_desc.getwidth()) / 2 + OFFSET_X;
	img_2p_desc_position.y = img_1p_desc_position.y;

	img_1p_gravestone_position.x = (getwidth() / 2 - img_gravestone_right.getwidth()) / 2 - OFFSET_X;
	img_1p_gravestone_position.y = img_1p_position.y + img_1p.getheight() + 35;
	img_2p_gravestone_position.x = getwidth() / 2 + (getwidth() / 2 - img_gravestone_left.getwidth()) / 2 + OFFSET_X;
	img_2p_gravestone_position.y = img_1p_gravestone_position.y;

	animation_1p_position.x = (getwidth() / 2 - atlas_peashooter_idle_right.GetImage(0)->getheight()) / 2 - OFFSET_X;
	animation_1p_position.y = img_1p_gravestone_position.y + 80;
	animation_2p_position.x = getwidth() / 2 + (getwidth() / 2 - atlas_peashooter_idle_right.GetImage(0)->getheight()) / 2 + OFFSET_X;
	animation_2p_position.y = img_2p_gravestone_position.y + 80;

	img_1p_name_position.x = animation_1p_position.x + WINDOW_WIDTH / 100;
	img_1p_name_position.y = animation_1p_position.y + 155;
	img_2p_name_position.x = animation_2p_position.x + WINDOW_WIDTH / 100;
	img_2p_name_position.y = animation_2p_position.y + 155;

	btn_1p_selector_scene_left.x = img_1p_gravestone_position.x - img_1p_selector_scene_btn_idle_left.getwidth();
	btn_1p_selector_scene_left.y = img_1p_gravestone_position.y + (img_gravestone_right.getheight() - img_1p_selector_scene_btn_idle_left.getheight()) / 2;
	btn_1p_selector_scene_right.x = img_1p_gravestone_position.x + img_gravestone_right.getwidth();
	btn_1p_selector_scene_right.y = btn_1p_selector_scene_left.y;

	btn_2p_selector_scene_left.x = img_2p_gravestone_position.x - img_2p_selector_scene_btn_idle_Left.getwidth();
	btn_2p_selector_scene_left.y = btn_1p_selector_scene_left.y;
	btn_2p_selector_scene_right.x = img_2p_gravestone_position.x + img_gravestone_left.getwidth();
	btn_2p_selector_scene_right.y = btn_1p_selector_scene_left.y;
}

void SelectorScene::Input(ExMessage& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		switch (msg.vkcode)
		{
		case 0x41: // 'a'
			is_btn_1P_left_down = true;
			break;
		case 0x44: // 'd'
			is_btn_1P_right_down = true;
			break;
		case VK_LEFT: // '©'
			is_btn_2P_left_down = true;
			break;
		case VK_RIGHT: // '¨'
			is_btn_2P_right_down = true;
			break;
		default:
			break;
		}
		break;
	case WM_KEYUP:
		switch (msg.vkcode)
		{
		case 0x41: // 'a'
			is_btn_1P_left_down = false;
			player_type_1 = (PlayerType)(((int)PlayerType::Invalid + (int)player_type_1 - 1) % (int)PlayerType::Invalid);
			mciSendStringW(_T("play ui_switch from 0"), NULL, 0, NULL);
			break;
		case 0x44: // 'd'
			is_btn_1P_right_down = false;
			player_type_1 = (PlayerType)(((int)PlayerType::Invalid + (int)player_type_1 + 1) % (int)PlayerType::Invalid);
			mciSendStringW(_T("play ui_switch from 0"), NULL, 0, NULL);
			break;
		case VK_LEFT: // '©'
			is_btn_2P_left_down = false;
			player_type_2 = (PlayerType)(((int)PlayerType::Invalid + (int)player_type_2 - 1) % (int)PlayerType::Invalid);
			mciSendStringW(_T("play ui_switch from 0"), NULL, 0, NULL);
			break;
		case VK_RIGHT: // '¨'
			is_btn_2P_right_down = false;
			player_type_2 = (PlayerType)(((int)PlayerType::Invalid + (int)player_type_2 + 1) % (int)PlayerType::Invalid);
			mciSendStringW(_T("play ui_switch from 0"), NULL, 0, NULL);
			break;
		case VK_RETURN: // 'Enter'
			mciSendStringW(_T("play ui_confirm from 0"), NULL, 0, NULL);
			scene_manager.SwitchTo(SceneManager::SceneType::Game);
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
	animation_peashooter_left.Update(delta);
	animation_peashooter_right.Update(delta);
	animation_sunflower_left.Update(delta);
	animation_sunflower_right.Update(delta);

	// Dyanamic background
	selector_background_scorll_offset_x += 5;
	if (selector_background_scorll_offset_x >= img_peashooter_selector_scene_background_left.getwidth())
	{
		selector_background_scorll_offset_x = 0;
	}
	
	// Dynamic btn update
	btnplus ? btn_offset += 400 : btn_offset -= 400;

	if (btn_offset / WINDOW_WIDTH >= 10)
	{
		btnplus = false;
	}
	else if (btn_offset / WINDOW_WIDTH <= 0)
	{
		btnplus = true;
	}
}
void SelectorScene::Draw(Camera& camera)
{
	IMAGE* p_p1_selector_background = nullptr;
	IMAGE* p_p2_selector_background = nullptr;

	switch (player_type_1)
	{
	case SelectorScene::PlayerType::Peashooter:
		p_p1_selector_background = &img_peashooter_selector_scene_background_Right;
		break;
	case SelectorScene::PlayerType::Sunflower:
		p_p1_selector_background = &img_sunflower_selector_scene_background_Right;
		break;
	default:
		p_p1_selector_background = nullptr;
		break;
	}
	switch (player_type_2)
	{
	case SelectorScene::PlayerType::Peashooter:
		p_p2_selector_background = &img_peashooter_selector_scene_background_left;
		break;
	case SelectorScene::PlayerType::Sunflower:
		p_p2_selector_background = &img_sunflower_selector_scene_background_left;
		break;
	default:
		p_p1_selector_background = nullptr;
		break;
	}

	putimage(0, 0, &img_selector_scene_background, SRCCOPY);

	// Dynamic background
	if(p_p1_selector_background && p_p2_selector_background)
	{
		PutImageAlpha(camera, selector_background_scorll_offset_x - p_p1_selector_background->getwidth(), 0, p_p1_selector_background);
		PutImageAlpha(selector_background_scorll_offset_x, 0,
			p_p1_selector_background->getwidth() - selector_background_scorll_offset_x, 0, p_p1_selector_background, 0, 0);
		PutImageAlpha(getwidth() - p_p2_selector_background->getwidth(), 0,
			p_p2_selector_background->getwidth() - selector_background_scorll_offset_x, 0, p_p2_selector_background, selector_background_scorll_offset_x, 0);
		PutImageAlpha(camera, getwidth() - selector_background_scorll_offset_x, 0, p_p2_selector_background);
	}

	PutImageAlpha(camera, img_vs_position.x, img_vs_position.y, &img_vs);
	PutImageAlpha(camera, img_1p_position.x, img_1p_position.y, &img_1p);
	PutImageAlpha(camera, img_2p_position.x, img_2p_position.y, &img_2p);

	PutImageAlpha(camera, img_1p_desc_position.x, img_1p_desc_position.y, &img_1p_desc);
	PutImageAlpha(camera, img_2p_desc_position.x, img_2p_desc_position.y, &img_2p_desc);

	PutImageAlpha(camera, img_1p_gravestone_position.x, img_1p_gravestone_position.y, &img_gravestone_left);
	PutImageAlpha(camera, img_2p_gravestone_position.x, img_2p_gravestone_position.y, &img_gravestone_right);

	PutImageAlpha(camera, img_tip_position.x, img_tip_position.y, &img_tip);

	PutImageAlpha(camera, btn_1p_selector_scene_left.x - btn_offset / WINDOW_WIDTH, btn_1p_selector_scene_left.y, is_btn_1P_left_down ? &img_1p_selector_scene_btn_down_Left : &img_1p_selector_scene_btn_idle_left);
	PutImageAlpha(camera, btn_1p_selector_scene_right.x + btn_offset / WINDOW_WIDTH, btn_1p_selector_scene_right.y, is_btn_1P_right_down ? &img_1p_selector_scene_btn_down_Right : &img_1p_selector_scene_btn_idle_Right);
	PutImageAlpha(camera, btn_2p_selector_scene_left.x - btn_offset / WINDOW_WIDTH, btn_2p_selector_scene_left.y, is_btn_2P_left_down ? &img_2p_selector_scene_btn_down_Left : &img_2p_selector_scene_btn_idle_Left);
	PutImageAlpha(camera, btn_2p_selector_scene_right.x + btn_offset / WINDOW_WIDTH, btn_2p_selector_scene_right.y, is_btn_2P_right_down ? &img_2p_selector_scene_btn_down_Right : &img_2p_selector_scene_btn_idle_Right);
	
	switch (player_type_1)
	{
	case PlayerType::Peashooter:
		animation_peashooter_right.Draw(camera, animation_1p_position.x, animation_1p_position.y);
		img_1p_name_position.x = img_1p_gravestone_position.x + ((img_gravestone_right.getwidth() - textwidth(str_peashooter_name)) / 2);
		OuttextxyShaded(img_1p_name_position.x, img_1p_name_position.y, str_peashooter_name);
		break;
	case PlayerType::Sunflower:
		animation_sunflower_right.Draw(camera, animation_1p_position.x, animation_1p_position.y);
		img_1p_name_position.x = img_1p_gravestone_position.x + ((img_gravestone_right.getwidth() - textwidth(str_sunflower_name)) / 2);
		OuttextxyShaded(img_1p_name_position.x, img_1p_name_position.y, str_sunflower_name);
		break;
	}
	switch (player_type_2)
	{
	case PlayerType::Peashooter:
		animation_peashooter_left.Draw(camera, animation_2p_position.x, animation_2p_position.y);
		img_2p_name_position.x = img_2p_gravestone_position.x + ((img_gravestone_left.getwidth() - textwidth(str_peashooter_name)) / 2);
		OuttextxyShaded(img_2p_name_position.x, img_2p_name_position.y, str_peashooter_name);
		break;
	case PlayerType::Sunflower:
		animation_sunflower_left.Draw(camera, animation_2p_position.x, animation_2p_position.y);
		img_2p_name_position.x = img_2p_gravestone_position.x + ((img_gravestone_left.getwidth() - textwidth(str_sunflower_name)) / 2);
		OuttextxyShaded(img_2p_name_position.x, img_2p_name_position.y, str_sunflower_name);
		break;
	}
}
void SelectorScene::Exit()
{
	mciSendStringW(_T("stop bgm_menu"), NULL, 0, NULL);

	//
	switch (player_type_1)
	{
	case SelectorScene::PlayerType::Peashooter:
		player_1 = new Peashooter();
		player_1->SetCharacter(Character::peashooter);
		break;
	case SelectorScene::PlayerType::Sunflower:
		player_1 = new Sunflower();
		player_1->SetCharacter(Character::sunflower);
		break;
	}
	player_1->SetID(PlayerID::P1);

	//
	switch (player_type_2)
	{
	case SelectorScene::PlayerType::Peashooter:
		player_2 = new Peashooter();
		player_2->SetCharacter(Character::peashooter);
		break;
	case SelectorScene::PlayerType::Sunflower:
		player_2 = new Sunflower();
		player_2->SetCharacter(Character::sunflower);
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