#include "Animation.h"
//コンストラクタ
Animation::Animation()
{
    playerModel = -1;
    idleModel = -1;
    runModel = -1;

    attachIndex = -1;

    playTime = 0;

    totalTime = 0;

    running = false;
}
//デストラクタ
Animation::~Animation()
{
    MV1DeleteModel(idleModel);
    MV1DeleteModel(runModel);
}
//アニメーションのロード
bool Animation::Load(int model)
{
    //プレイヤー現在モデル
    playerModel = model;
    //アイドリング、ランモデルをロード
    idleModel = MV1LoadModel("Player/Anim_Neutral.mv1");
    runModel = MV1LoadModel("Player/Anim_Run.mv1");

    attachIndex = MV1AttachAnim(playerModel, 0, idleModel);

    totalTime = MV1GetAttachAnimTotalTime(playerModel, attachIndex);

    return true;
}
//アニメーションの更新
void Animation::Update()
{
    //プレイヤータイムの増加
    playTime += 0.5f;
    //フレームの初期化
    if (playTime > totalTime) { playTime = 0; }
    //プレイヤータイムの更新
    MV1SetAttachAnimTime(playerModel, attachIndex, playTime);
}

void Animation::PlayIdle()
{
    if (!running)return;

    running = false;

    MV1DetachAnim(playerModel, attachIndex);

    attachIndex = MV1AttachAnim(playerModel, 0, idleModel);

    totalTime = MV1GetAttachAnimTotalTime(playerModel, attachIndex);

    playTime = 0;
}

void Animation::PlayRun()
{
    if (running)return;

    running = true;

    MV1DetachAnim(playerModel, attachIndex);

    attachIndex = MV1AttachAnim(playerModel, 0, runModel);

    totalTime = MV1GetAttachAnimTotalTime(playerModel, attachIndex);

    playTime = 0;
}