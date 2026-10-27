#include"Dxlib.h"
#include"Config.h"
#include"Player.h"
#include"Camera.h"
#include<algorithm>

static void DrawField() 
{
	const float size = Config::FIELD_HALF_SIZE;

	DrawCube3D(VGet(-size, 0.1f, -size), VGet(size, 0.0f, size), GetColor(70, 150, 80), GetColor(70, 150, 80), TRUE);

	const int lineColor = GetColor(220, 220, 200);

	DrawLine3D(VGet(-size, 0.02f, -size), VGet(size, 0.02f, -size), lineColor);
	DrawLine3D(VGet(size, 0.02f, -size), VGet(size, 0.02f, size), lineColor);
	DrawLine3D(VGet(size, 0.02f, size), VGet(-size, 0.02f, size), lineColor);
	DrawLine3D(VGet(-size, 0.02f, size), VGet(-size, 0.02f, -size), lineColor);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	ChangeWindowMode(TRUE);
	SetGraphMode(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, 32);
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	SetUseLighting(TRUE);
	ChangeLightTypeDir(VGet(1.0f, 10.0f, 0.0f));

	Player player;
	Camera camera;

	int previousTime = GetNowCount();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) 
	{
		//前回のフレームからの経過時間を秒で求める
		const int currentTime = GetNowCount();
		float deltaTime = static_cast<float>(currentTime - previousTime) / 1000.0f;
		previousTime = currentTime;

		//処理落ちなどで移動量が極端に大きくならないようにする
		//deltaTime = std::min(deltaTime, 0.05f);

		//更新処理
		player.Update(deltaTime);

		camera.Update(player);

		//描画処理
		ClearDrawScreen();
		
		DrawField();
		player.Draw();

		DrawFormatString(20, 20, GetColor(255, 255, 255), "Arrow keys: Move   ESC: Exit");


		ScreenFlip();

	}
	DxLib_End();

	return 0;
}

