#include "Player.h"
#include "20260714_Config.h"

bool Player::Load()
{
    model = MV1LoadModel("Player/PC.mv1");

    pos = VGet(600, 300, -400);

    dir = DOWN;

    animation.Load(model);

    int root = MV1SearchFrame(model, "root");

    MV1SetFrameUserLocalMatrix(model, root, MGetIdent());

    return true;
}

void Player::Update()
{
    bool move = false;

    if (CheckHitKey(KEY_INPUT_DOWN))
    {
        pos.z -= Config::PLAYER_SPEED;
        dir = DOWN;
        move = true;
    }

    if (CheckHitKey(KEY_INPUT_UP))
    {
        pos.z += Config::PLAYER_SPEED;
        dir = UP;
        move = true;
    }

    if (CheckHitKey(KEY_INPUT_LEFT))
    {
        pos.x -= Config::PLAYER_SPEED;
        dir = LEFT;
        move = true;
    }

    if (CheckHitKey(KEY_INPUT_RIGHT))
    {
        pos.x += Config::PLAYER_SPEED;
        dir = RIGHT;
        move = true;
    }

    if (move)
        animation.PlayRun();
    else
        animation.PlayIdle();

    animation.Update();
}

void Player::Draw()
{
    MV1SetRotationXYZ(model, VGet(0, 1.57f * dir, 0));

    MV1SetPosition(model, pos);

    MV1DrawModel(model);
}

VECTOR Player::GetPosition()const
{
    return pos;
}

float Player::GetAngle()const
{
    return 1.57f * dir;
}