#include "Player.h"
#include "Config.h"
#include "Dxlib.h"

#include<cmath>
using namespace std;
//コンストラクタ
Player::Player() :x(0.0f), y(0.0f), z(0.0f) {}

//更新
void Player::Update(float deltaTime) 
{
	float moveX = 0.0f;
	float moveZ = 0.0f;

	if (CheckHitKey(KEY_INPUT_W))moveZ += 1.0f;
	if (CheckHitKey(KEY_INPUT_S))moveZ -= 1.0f;
	if (CheckHitKey(KEY_INPUT_A))moveX -= 1.0f;
	if (CheckHitKey(KEY_INPUT_D))moveX += 1.0f;

	const float leagth = sqrt(moveX * moveX + moveZ * moveZ);

	if (leagth > 0.0f) 
	{
		moveX /= leagth;
		moveZ /= leagth;

		x += moveX * Config::PLAYER_MOVE_SPEED * deltaTime;
		z += moveZ * Config::PLAYER_MOVE_SPEED * deltaTime;
	}

	

}


void Player::Draw()const 
{
	const VECTOR bottom = VGet(x, y + Config::PLAYER_HEIGHT, z);
	const VECTOR top = VGet(x, y + Config::PLAYER_HEIGHT - Config::PLAYER_RADIUS, z);

	const int blue = GetColor(50, 120, 255);

	DrawCapsule3D(bottom, top, Config::PLAYER_RADIUS, 8, GetColor(50, 120, 255), GetColor(50, 120, 255), TRUE);
}

float Player::GetX() const { return x; }
float Player::GetY() const { return y; }
float Player::GetZ() const { return z; }
