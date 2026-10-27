#include "Camera.h"
#include "Player.h"
#include "Config.h"
#include "Dxlib.h"

void Camera::Update(const Player& player) const 
{
	const VECTOR cameraPosition = VGet(player.GetX(),player.GetY() + Config::CAMERA_HEIGHT,player.GetZ() - Config::CAMERA_DISTANCE);
	const VECTOR targetPosition = VGet(player.GetX(),player.GetY(),player.GetZ());

	SetCameraPositionAndTarget_UpVecY(cameraPosition,targetPosition);
}

