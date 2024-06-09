#pragma comment(lib, "Winmm.lib")

#include <graphics.h>

#include <iostream>

#include "Global.h"

#include "MenuScene.h"
#include "GameScene.h"
#include "SelectorScene.h"

#include "Util.h"

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

	menuScene = new MenuScene();
	gameScene = new GameScene();
	selectorScene = new SelectorScene();

	Atlas AtlasPeashooterIdleRight;
	AtlasPeashooterIdleRight.LoadFromFile(_T("resources/peashooter_idle_%d.png"), 9);

	sceneManager.SetCurrentScene(menuScene);

	menuScene->Enter();

	while (true)
	{
		clock_t startTime = clock();

		// Process Event
		while (peekmessage(&msg))
		{
			sceneManager.Input(msg);
		}

		// Update data
		sceneManager.Update(15);

		// Draw
		cleardevice();
		sceneManager.Draw(camera);

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