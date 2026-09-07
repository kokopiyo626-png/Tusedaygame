#include "Object3D.h"

Object3D::Object3D()
{
    modelHandle = -1;
    position = VGet(0.0f, 0.0f, 0.0f);
    collisionRadius = 50.0f;
}
Object3D::~Object3D()
{
    if (modelHandle != -1)
    {
        MV1DeleteModel(modelHandle);
    }
}

bool Object3D::Load(const char* fileName, float radius)
{
    modelHandle = MV1LoadModel("Stage/Stage_Obj001.mv1");
    if (modelHandle == -1)
    {
        return false;
    }

    collisionRadius = radius;

    MV1SetPosition(modelHandle, position);

    return true;
}

void Object3D::SetPosition(VECTOR pos)
{
    position = pos;
    if (modelHandle != -1)
    {
        MV1SetPosition(modelHandle, position);
    }
}

VECTOR Object3D::GetPosition() const
{
    return position;
}

float Object3D::GetCollisionRadius() const
{
    return collisionRadius;
}

void Object3D::Draw() 
{
    if (modelHandle == -1)
    {
        return;
    }

    MV1DrawModel(modelHandle);

}

