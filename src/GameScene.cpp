#include "GameScene.h"

void GameScene::Enter()
{
	pos_imgSky.x = (getwidth() - imgSky.getwidth()) / 2;
	pos_imgSky.y = (getheight() - imgSky.getheight()) / 2;

	pos_imgHills.x = (getwidth() - imgHills.getwidth()) / 2;
	pos_imgHills.y = (getheight() - imgHills.getheight()) / 2;

	platform_list.resize(4);

	Platform& large_platform = platform_list[0];
	large_platform.img = &imgPlatformLarge;
	large_platform.render_position.x = 122;
	large_platform.render_position.y = 455;
	large_platform.shape.y = large_platform.render_position.y + 60;
	large_platform.shape.left = large_platform.render_position.x + 30;
	large_platform.shape.right = large_platform.render_position.x + large_platform.img->getwidth() - 30;

	Platform& small_platform_1 = platform_list[1];
	small_platform_1.img = &imgPlatformSmall;
	small_platform_1.render_position.x = 175;
	small_platform_1.render_position.y = 360;
	small_platform_1.shape.y = small_platform_1.render_position.y + small_platform_1.img->getheight() / 2;
	small_platform_1.shape.left = small_platform_1.render_position.x + 40;
	small_platform_1.shape.right = small_platform_1.render_position.x + small_platform_1.img->getwidth() - 40;

	Platform& small_platform_2 = platform_list[2];
	small_platform_2.img = &imgPlatformSmall;
	small_platform_2.render_position.x = 855;
	small_platform_2.render_position.y = 360;
	small_platform_2.shape.y = small_platform_2.render_position.y + small_platform_2.img->getheight() / 2;
	small_platform_2.shape.left = small_platform_2.render_position.x + 40;
	small_platform_2.shape.right = small_platform_2.render_position.x + small_platform_2.img->getwidth() - 40;

	Platform& small_platform_3 = platform_list[3];
	small_platform_3.img = &imgPlatformSmall;
	small_platform_3.render_position.x = 515;
	small_platform_3.render_position.y = 225;
	small_platform_3.shape.y = small_platform_3.render_position.y + small_platform_3.img->getheight() / 2;
	small_platform_3.shape.left = small_platform_3.render_position.x + 40;
	small_platform_3.shape.right = small_platform_3.render_position.x + small_platform_3.img->getwidth() - 40;

	player_1->SetPosition(200, 100);
	player_2->SetPosition(700, 100);
}
void GameScene::Input(ExMessage& msg)
{
	player_1->Input(msg);
	player_2->Input(msg);

	switch (msg.message)
	{
	case WM_KEYUP:
		if (msg.vkcode == 0x51)
		{
			is_debug = !is_debug;
		}
		break;
	default:
		break;
	}
}
void GameScene::Update(int& delta)
{
	player_1->Update(delta);
	player_2->Update(delta);
}
void GameScene::Draw(Camera& camera)
{
	PutImageAlpha(camera, pos_imgSky.x, pos_imgSky.y, &imgSky);
	PutImageAlpha(camera, pos_imgHills.x, pos_imgHills.y, &imgHills);

	for (Platform& platform : platform_list)
	{
		platform.Draw(camera);
	}

	if (is_debug)
	{
		settextcolor(RGB(255, 0, 0));
		outtextxy(15, 15, _T("Debug mode"));
	}

	player_1->Draw(camera);
	player_2->Draw(camera);
}
void GameScene::Exit()
{
	
}