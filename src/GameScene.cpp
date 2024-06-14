#include "GameScene.h"

// Default
void GameScene::Enter()
{
	img_sky_position.x = (getwidth() - img_sky.getwidth()) / 2;
	img_sky_position.y = (getheight() - img_sky.getheight()) / 2;

	img_hills_position.x = (getwidth() - img_hills.getwidth()) / 2;
	img_hills_position.y = (getheight() - img_hills.getheight()) / 2;

	platform_list.resize(4);

	Platform& large_platform = platform_list[0];
	large_platform.img = &img_platform_large;
	large_platform.render_position.x = 122;
	large_platform.render_position.y = 455;
	large_platform.shape.y = large_platform.render_position.y + 60;
	large_platform.shape.left = large_platform.render_position.x + 30;
	large_platform.shape.right = large_platform.render_position.x + large_platform.img->getwidth() - 30;

	Platform& small_platform_1 = platform_list[1];
	small_platform_1.img = &img_platform_small;
	small_platform_1.render_position.x = 175;
	small_platform_1.render_position.y = 360;
	small_platform_1.shape.y = small_platform_1.render_position.y + small_platform_1.img->getheight() / 2;
	small_platform_1.shape.left = small_platform_1.render_position.x + 40;
	small_platform_1.shape.right = small_platform_1.render_position.x + small_platform_1.img->getwidth() - 40;

	Platform& small_platform_2 = platform_list[2];
	small_platform_2.img = &img_platform_small;
	small_platform_2.render_position.x = 855;
	small_platform_2.render_position.y = 360;
	small_platform_2.shape.y = small_platform_2.render_position.y + small_platform_2.img->getheight() / 2;
	small_platform_2.shape.left = small_platform_2.render_position.x + 40;
	small_platform_2.shape.right = small_platform_2.render_position.x + small_platform_2.img->getwidth() - 40;

	Platform& small_platform_3 = platform_list[3];
	small_platform_3.img = &img_platform_small;
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
	camera.Update(delta);

	player_1->Update(delta);
	player_2->Update(delta);

	for (Bullet* bullet : bullet_list)
	{
		bullet->Update(delta);
	}

	// Delete bullet
	
	bullet_list.erase(std::remove_if(
		bullet_list.begin(), bullet_list.end(),
		[](Bullet* bullet)
		{
			bool deletable = bullet->GetCanRemove();
			if (deletable)
			{
				delete bullet;
			}
			return deletable;
		}),
		bullet_list.end());
	
	/*
	for (size_t i = 0; i < bullet_list.size(); i++)
	{
		if (bullet_list[i]->GetCanRemove())
		{
			Bullet* tmp = bullet_list[i];
			std::swap(bullet_list[i], bullet_list.back());
			bullet_list.pop_back();
			delete tmp;
		}
	}
	*/
}

void GameScene::Draw(Camera& camera)
{
	PutImageAlpha(camera, img_sky_position.x, img_sky_position.y, &img_sky);
	PutImageAlpha(camera, img_hills_position.x, img_hills_position.y, &img_hills);

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

	for (Bullet* bullet : bullet_list)
	{
		bullet->Draw(camera);
	}
}

void GameScene::Exit()
{
	
}