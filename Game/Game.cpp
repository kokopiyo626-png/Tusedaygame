#include "Game.h"
#include"Dxlib.h"
#include"Collsion.h"
//===============================
// 初期化
//===============================
void Game::Init()
{
	player.Init(VGet(-100, 0, 0), 30.0f, 80.0f, GetColor(255, 255, 255));
	enemy.Init(VGet(100, 0, 0), 30.0f, 80.0f, GetColor(255, 255, 0));
}

//======================================
// 床描画
//======================================
void Game::DrawFloor()
{
	//----------------------------------
	// グリッドの設定
	//----------------------------------
	const int GRID_NUM = 20;
	const float GRID_SIZE = 20.0f;

	//----------------------------------
	// グリッド
	//----------------------------------

	// グリッドの描画
	for (int i = -GRID_NUM; i <= GRID_NUM; i++)
	{
		// Z方向

		DrawLine3D(VGet(i * GRID_SIZE, 0, -GRID_NUM * GRID_SIZE), VGet(i * GRID_SIZE, 0, GRID_NUM * GRID_SIZE), GetColor(180, 180, 180));

		// X方向
		DrawLine3D(VGet(-GRID_NUM * GRID_SIZE, 0, i * GRID_SIZE), VGet(GRID_NUM * GRID_SIZE, 0, i * GRID_SIZE), GetColor(180, 180, 180));
	}

	//----------------------------------
	// X軸（赤）
	//----------------------------------

	DrawLine3D(VGet(-500, 0, 0), VGet(500, 0, 0), GetColor(255, 0, 0));

	//----------------------------------
	// Z軸（青）
	//----------------------------------

	DrawLine3D(VGet(0, 0, -500), VGet(0, 0, 500), GetColor(0, 0, 255));
}

void Game::Update()
{
	//--------------------------------
	// キャラクターの更新
	//--------------------------------
	player.Update();
	//--------------------------------
	// 敵の更新
	//--------------------------------
	if (Collision::CheckHit(player, enemy))
	{
		Collision::PushBack(player, enemy);
	}
}

void Game::Draw()
{
	//----------------------------------
	// カメラ
	//----------------------------------

	SetCameraPositionAndTarget_UpVecY(VGet(0, 150, -300), VGet(0, 30, 0));

	//----------------------------------
	// 床
	//----------------------------------

	DrawFloor();

	//----------------------------------
	// キャラクター
	//----------------------------------

	player.Draw();

	enemy.Draw();

	//----------------------------------
	// 説明表示
	//----------------------------------

	// 当たり判定の結果を表示
	bool hit = Collision::CheckHit(player, enemy);

	//--------------------------------
	// 当たり判定の結果を表示
	//--------------------------------
	DrawFormatString(20, 20, GetColor(255, 255, 255), "Collision : %s", hit ? "TRUE" : "FALSE");

	DrawString(20, 50, "Arrow Key Move", GetColor(255, 255, 0));
}
