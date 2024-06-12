#include "MenuScene.h"

void MenuScene::Enter()
{
	mciSendStringW(_T("play bgm_menu repeat from 0"), NULL, 0, NULL);
}
void MenuScene::Input(ExMessage& msg)
{
	/*
	if (msg.message == WM_KEYUP)
	{
		mciSendStringW(_T("play ui_confirm from 0"), NULL, 0, NULL);
		scene_manager.SwitchTo(SceneManager::SceneType::Selector);
	}
	*/
	if (msg.message == WM_KEYUP)
	{
		camera.Shake(5, 60);
	}
}
void MenuScene::Update(int& delta)
{

}
void MenuScene::Draw(Camera& camera)
{
	//putimage(0, 0, &imgMenuBackground, SRCCOPY);
	putimage(0 - camera.GetPosition().x, 0 - camera.GetPosition().y, &imgMenuBackground, SRCCOPY);
}
void MenuScene::Exit()
{
	
}