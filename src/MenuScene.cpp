#include "MenuScene.h"

// Default
void MenuScene::Enter()
{
	mciSendStringW(_T("play bgm_menu repeat from 0"), NULL, 0, NULL);
}

void MenuScene::Input(ExMessage& msg)
{
	if (msg.message == WM_KEYUP)
	{
		mciSendStringW(_T("play ui_confirm from 0"), NULL, 0, NULL);
		scene_manager.SwitchTo(SceneManager::SceneType::Selector);
	}
}

void MenuScene::Update(int& delta)
{

}

void MenuScene::Draw(Camera& camera)
{
	putimage(0, 0, &img_menu_background, SRCCOPY);
}

void MenuScene::Exit()
{
	
}