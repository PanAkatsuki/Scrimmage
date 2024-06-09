#include "MenuScene.h"

MenuScene::MenuScene()
{

}
MenuScene::~MenuScene()
{

}

void MenuScene::Enter()
{
	mciSendStringW(_T("play bgm_menu repeat from 0"), NULL, 0, NULL);
}
void MenuScene::Input(ExMessage& msg)
{
	if (msg.message == WM_KEYUP)
	{
		mciSendStringW(_T("stop bgm_menu"), NULL, 0, NULL);
		mciSendStringW(_T("play ui_confirm from 0"), NULL, 0, NULL);
		sceneManager.SwitchTo(SceneManager::sceneType::Selector);
	}
}
void MenuScene::Update(int& delta)
{

}
void MenuScene::Draw(Camera& camera)
{
	putimage(0, 0, &imgMenuBackground, SRCCOPY);
}
void MenuScene::Exit()
{
	std::cout << "Exit Menu" << std::endl;
}