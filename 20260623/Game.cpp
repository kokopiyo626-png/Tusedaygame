#include "Game.h"

bool Game::Init()
{
    //プレイヤーを初期化
    player.Load();

    return true;
}

void Game::Update()
{
    //プレイヤー更新
    player.Update();
    //カメラ更新
    camera.Update(player);
}

void Game::Draw()
{
    //画面の初期化
    ClearDrawScreen();
    //背景を描画
    DrawBox(0, 0, 1200, 800, GetColor(255, 255, 255), TRUE);
    //プレイヤーの描画
    player.Draw();
    //リフレッシュ
    ScreenFlip();
}