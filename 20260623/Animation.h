#pragma once
#include "DxLib.h"

class Animation
{
public:

    //インスタンス
    Animation();
    ~Animation();
    //アニメーションのモデルロード
    bool Load(int model);
    //アニメーションの更新
    void Update();
    //アニメーションの状態（走る）
    void PlayRun();
    //アニメーションの状態（止まっている）
    void PlayIdle();

private:

    int playerModel;

    int idleModel;
    int runModel;

    int attachIndex;

    float playTime;
    float totalTime;

    bool running;
};