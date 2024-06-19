#include "GameScene.h"

// Default
void GameScene::Enter()
{
	// Background position
	position_img_sky.x = (getwidth() - img_sky.getwidth()) / 2;
	position_img_sky.y = (getheight() - img_sky.getheight()) / 2;

	position_img_hills.x = (getwidth() - img_hills.getwidth()) / 2;
	position_img_hills.y = (getheight() - img_hills.getheight()) / 2;

	// Load platform
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

	// Set player's position
	player_1->SetPosition(WINDOW_WIDTH / 10 * 2 - CHARACTER_SIZE_X / 2, WINDOW_HEIGHT / 10);
	player_2->SetPosition(WINDOW_WIDTH / 10 * 8 - CHARACTER_SIZE_X / 2, WINDOW_HEIGHT / 10);

	// Set status bar hp mp
	status_bar_p1.SetHP(player_1->GetHP());
	status_bar_p1.SetMP(player_1->GetMP());
	status_bar_p2.SetHP(player_2->GetHP());
	status_bar_p2.SetMP(player_2->GetMP());

	// Set status bar avatar
	switch (player_1->GetCharacter())
	{
	case Character::NONE:
		break;
	case Character::peashooter:
		status_bar_p1.SetAvatar(&img_avatar_peashooter);
		break;
	case Character::sunflower:
		status_bar_p1.SetAvatar(&img_avatar_sunflower);
		break;
	}

	switch (player_2->GetCharacter())
	{
	case Character::NONE:
		break;
	case Character::peashooter:
		status_bar_p2.SetAvatar(&img_avatar_peashooter);
		break;
	case Character::sunflower:
		status_bar_p2.SetAvatar(&img_avatar_sunflower);
		break;
	}

	// Set status bar position
	status_bar_p1.SetPosition(235, 625);
	status_bar_p2.SetPosition(675, 625);

	// Set bool
	is_game_over = false;
	is_slide_out_started = false;

	// Set winner bar and winner text
	position_img_winner_bar.x = -img_winner_bar.getwidth();
	position_img_winner_bar.y = (getheight() - img_winner_bar.getheight()) / 2;
	position_x_img_winner_bar_dst = (getwidth() - img_winner_bar.getwidth()) / 2;
	speed_slide_in_bar = (position_x_img_winner_bar_dst - position_img_winner_bar.x) / (time_winner_slide_in / 2);

	position_img_winner_text.x = -img_1p_winner.getwidth();
	position_img_winner_text.y = (getheight() - img_1p_winner.getheight()) / 2;
	position_x_img_winner_text_dst = (getwidth() - img_1p_winner.getwidth()) / 2;
	speed_slide_in_text = (position_x_img_winner_text_dst - position_img_winner_text.x) / (time_winner_slide_in / 2);

	speed_slide_out_bar = (getwidth() - position_x_img_winner_bar_dst) / (time_winner_slide_out);
	speed_slide_out_text = (getwidth() - position_x_img_winner_text_dst) / (time_winner_slide_out);

	timer_winner_slide_in.Restart();
	timer_winner_slide_in.SetWaitTime(time_winner_slide_in);
	timer_winner_slide_in.SetOneShot(true);
	timer_winner_slide_in.SetCallback(
		[&]()
		{
			is_slide_out_started = true;
		}
	);

	timer_winner_slide_out.Restart();
	timer_winner_slide_out.SetWaitTime(time_winner_slide_out);
	timer_winner_slide_out.SetOneShot(true);
	timer_winner_slide_out.SetCallback(
		[&]()
		{
			is_slide_out_started = false;
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
		}
	);

	// Music
	mciSendStringW(_T("play bgm_game repeat from 0"), NULL, 0, NULL);
}

void GameScene::Input(ExMessage& msg)
{
	player_1->Input(msg);
	player_2->Input(msg);

	switch (msg.message)
	{
	case WM_KEYUP: // 'Q'
		if (msg.vkcode == 0x51)
		{
			is_debug = !is_debug;
		}
		break;
	}
}

void GameScene::Update(int& delta)
{
	// Update camera
	camera.Update(delta);

	// Update player
	player_1->Update(delta);
	player_2->Update(delta);

	// Update status bar hp mp
	status_bar_p1.SetHP(player_1->GetHP());
	status_bar_p1.SetMP(player_1->GetMP());
	status_bar_p2.SetHP(player_2->GetHP());
	status_bar_p2.SetMP(player_2->GetMP());

	// Update bullet
	for (Bullet* bullet : bullet_list)
	{
		bullet->Update(delta);
	}

	// Delete invalid bullet
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

	// Check game over
	if (player_1->GetHP() <= 0 || player_2->GetHP() <= 0)
	{
		if (!is_game_over)
		{
			mciSendStringW(_T("stop bgm_game"), NULL, 0, NULL);
			mciSendStringW(_T("play ui_win from 0"), NULL, 0, NULL);
		}

		is_game_over = true;
	}

	// Game over update
	if (is_game_over)
	{
		if (!is_slide_out_started)
		{
			// Slide in
			timer_winner_slide_in.Update(delta);

			// Update winner bar and text position
			if (position_img_winner_bar.x < position_x_img_winner_bar_dst)
			{
				position_img_winner_bar.x += speed_slide_in_bar * delta;
				if (position_img_winner_bar.x >= position_x_img_winner_bar_dst)
				{
					position_img_winner_bar.x = position_x_img_winner_bar_dst;
				}
			}

			if (position_img_winner_text.x < position_x_img_winner_text_dst)
			{
				position_img_winner_text.x += speed_slide_in_text * delta;
				if (position_img_winner_text.x >= position_x_img_winner_text_dst)
				{
					position_img_winner_text.x = position_x_img_winner_text_dst;
				}
			}
		}

		// Slide out
		if (is_slide_out_started)
		{
			timer_winner_slide_out.Update(delta);

			position_img_winner_bar.x += speed_slide_out_bar * delta;
			if (position_img_winner_bar.x >= getwidth())
			{
				position_img_winner_bar.x = getwidth();
			}

			position_img_winner_text.x += speed_slide_out_text * delta;
			if (position_img_winner_text.x >= getwidth())
			{
				position_img_winner_text.x = getwidth();
			}
		}
	}
}

void GameScene::Draw(Camera& camera)
{
	// Draw background
	PutImageAlpha(camera, position_img_sky.x, position_img_sky.y, &img_sky);
	PutImageAlpha(camera, position_img_hills.x, position_img_hills.y, &img_hills);

	// Draw platform
	for (Platform& platform : platform_list)
	{
		platform.Draw(camera);
	}

	// Draw player
	player_1->Draw(camera);
	player_2->Draw(camera);

	// Draw bullet
	for (Bullet* bullet : bullet_list)
	{
		bullet->Draw(camera);
	}

	// Draw status bar
	status_bar_p1.Draw();
	status_bar_p2.Draw();

	// Draw game over bar
	if (is_game_over)
	{
		PutImageAlpha(camera, position_img_winner_bar.x, position_img_winner_bar.y, &img_winner_bar);

		if(player_1->GetHP() <= 0)
		{
			PutImageAlpha(camera, position_img_winner_text.x, position_img_winner_text.y, &img_2p_winner);
		}
		else if (player_2->GetHP() <= 0)
		{
			PutImageAlpha(camera, position_img_winner_text.x, position_img_winner_text.y, &img_1p_winner);
		}
	}

	// Debug view
	if (is_debug)
	{
		settextcolor(RGB(255, 0, 0));
		outtextxy(15, 15, _T("Debug mode"));
	}
}

void GameScene::Exit()
{
	delete player_1;
	player_1 = nullptr;
	delete player_2;
	player_2 = nullptr;

	is_debug = false;

	bullet_list.clear();
	camera.SetPosition(0, 0);
}