#pragma once

#include "DxLib.h"
#include "Animation.h"

class Player
{
public:

    enum Direction
    {
        DOWN,
        LEFT,
        UP,
        RIGHT
    };

    bool Load();

    void Update();

    void Draw();

    VECTOR GetPosition()const;

    float GetAngle()const;

private:

    int model;

    VECTOR pos;

    Direction dir;

    Animation animation;
};