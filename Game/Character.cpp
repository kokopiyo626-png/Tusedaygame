#include "Character.h"
//====================================
// コンストラクタ
//====================================
Character::Character()
{
	// 初期位置
	pos = VGet(0, 0, 0);
	// カプセルの半径
	radius = 30.0f;
	// カプセルの高さ
	height = 80.0f;
	// キャラクターの色
	color = GetColor(255, 255, 255);
}
//====================================
// 初期化
//====================================
void Character::Init(VECTOR startPos, float r, float h, unsigned int c)
{
	// 初期位置
	pos = startPos;
	// カプセルの半径
	radius = r;
	// カプセルの高さ
	height = h;
	// キャラクターの色
	color = c;
}
//====================================
// 更新
//====================================
void Character::Update()
{
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		pos.x -= 2.0f;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		pos.x += 2.0f;
	}

	if (CheckHitKey(KEY_INPUT_UP))
	{
		pos.z += 2.0f;
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		pos.z -= 2.0f;
	}
}
//====================================
// カプセルの上端
//====================================
VECTOR Character::GetCapsuleTop() const
{
	return VAdd(pos, VGet(0, height / 2, 0));
}
//====================================
// カプセルの下端
//====================================
VECTOR Character::GetCapsuleBottom() const
{
	return VAdd(pos, VGet(0, -height / 2, 0));
}

void Character::Draw()
{
	//----------------------------------
	// 円柱の上端
	//----------------------------------

	VECTOR top = VAdd(pos, VGet(0, height * 0.5f, 0));

	//----------------------------------
	// 円柱の下端
	//----------------------------------

	VECTOR bottom = VAdd(pos, VGet(0, -height * 0.5f, 0));

	//----------------------------------
	// 円柱描画
	//----------------------------------

	DrawCylinder3D(top, bottom, radius, 16, color, color, TRUE);

	//----------------------------------
	// 中心点表示
	//----------------------------------

	DrawSphere3D(pos, 5.0f, 8, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
}