#pragma comment(lib, "Winmm.lib")

#include <graphics.h>

#include <iostream>

#include "Global.h"

#include "MenuScene.h"
#include "GameScene.h"
#include "SelectorScene.h"

#include "Preprocess.h"

bool is_debug = false;

int main()
{
	// Test

	// End Test
	ExMessage msg;
	int fps = FPS_60;

	LoadGameResource();

	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT, NULL);

	settextstyle(28, 0, _T("IPix"));
	setbkmode(TRANSPARENT);

	BeginBatchDraw();

	menu_scene = new MenuScene();
	game_scene = new GameScene();
	selector_scene = new SelectorScene();

	scene_manager.SetCurrentScene(menu_scene);

	menu_scene->Enter();

	while (true)
	{
		clock_t startTime = clock();

		// Process Event
		while (peekmessage(&msg))
		{
			scene_manager.Input(msg);
		}

		// Update data
		scene_manager.Update(1);

		// Draw
		cleardevice();
		scene_manager.Draw(camera);

		FlushBatchDraw();

		clock_t endTime = clock();
		clock_t deltaTime = endTime - startTime;
		if (deltaTime < 1000 / fps)
		{
			Sleep(1000 / fps - deltaTime);
		}
	}

	EndBatchDraw();

}