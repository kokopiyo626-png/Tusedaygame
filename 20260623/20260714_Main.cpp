#include "DxLib.h"
#include "Game.h"
#include "20260714_Config.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);

    SetGraphMode(Config::WINDOW_W,Config::WINDOW_H,32);

    if (DxLib_Init() == -1) { return -1; }

    SetDrawScreen(DX_SCREEN_BACK);
    //ゲームクラスのインスタンス化
    Game game;
    //ゲームの初期化
    game.Init();
    //ゲームループ
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //ゲームの更新
        game.Update();
        //ゲームの描画
        game.Draw();
    }

    DxLib_End();

    return 0;
}