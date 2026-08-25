#pragma once
#include "DxLib.h"

const int STAGE_MODEL_NUM = 2;

class Stage
{
private:

    // ステージの3Dモデル
    int modelHandle[STAGE_MODEL_NUM];

    // ステージの位置
    VECTOR position[STAGE_MODEL_NUM];

public:

    // コンストラクタ
    Stage();

    // デストラクタ
    ~Stage();

    // ステージを読み込む
    bool Load();

    // ステージの位置を設定
    void SetPosition(VECTOR pos);

    // ステージを描画
    void Draw();
};