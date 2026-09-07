#include "Player.h"

Player::Player() 
{
    modelHandle = -1;

	position = VGet(0.0f, 0.0f, 0.0f);

    moveSpeed = 5.0f;

    collisionRadius = 50.0f;
}
Player::~Player() 
{
    if (modelHandle != -1)
    {
        MV1DeleteModel(modelHandle);
    }
}


bool Player::Load() 
{
   // modelHandle= MV1DeleteModel("")
    return true;
}


