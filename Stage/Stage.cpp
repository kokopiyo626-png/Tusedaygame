#include "Stage.h"

Stage::Stage()
{
    // モデルハンドルを初期化
    for (int i = 0; i < STAGE_MODEL_NUM; i++) 
    {
        modelHandle[i] = -1;
    }
   

    position[0] = VGet(0.0f, 0.0f, 0.0f);
    position[1] = VGet(1000.0f, 0.0f, 0.0f);

}

Stage::~Stage()
{
    // モデルを削除
    for (int i = 0; i < STAGE_MODEL_NUM; i++)
    {
        if (modelHandle[i] != -1)
        {
            MV1DeleteModel(modelHandle[i]);
        }
    }
   
}

bool Stage::Load()
{
    // 3Dモデルを読み込む
    modelHandle[0] = MV1LoadModel("Stage/Stage00.mv1");
    modelHandle[1] = MV1LoadModel("Stage/Stage01.mv1");

    // 読み込みチェック
    for (int i = 0; i < STAGE_MODEL_NUM; i++)
    {
        if (modelHandle[i] == -1)
        {
            return false;
        }
    }

    // 各モデルを配置
    for (int i = 0; i < STAGE_MODEL_NUM; i++)
    {
        MV1SetPosition(modelHandle[i], position[i]);
    }
   

    return true;
}

/*
void Stage::SetPosition(VECTOR pos)
{
    position = pos;

    // モデルが読み込まれている場合
    if (modelHandle != -1)
    {
        MV1SetPosition(modelHandle,position);
    }
}
*/


void Stage::Draw()
{
    for (int i = 0; i < STAGE_MODEL_NUM; i++)
    {
        if (modelHandle[i] == -1)
        {
            MV1DrawModel(modelHandle[i]);
            //return;
        }
    }
    // モデルが読み込まれていなければ何もしない
   

    // 3Dモデルを描画
   // MV1DrawModel(modelHandle);
}