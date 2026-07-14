#pragma once

#include "Player.h"
#include "Camera.h"

class Game
{
public:
    //初期化
    bool Init();
    //更新
    void Update();
    //描画
    void Draw();

private:
    //プレイヤー
    Player player;
    //カメラ
    Camera camera;
};