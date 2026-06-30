#include"Collsion.h"
#include <cmath>
//====================================
// 当たり判定
//====================================
bool Collsion::ChekHit(const Character& a, const Character& b)
{
	//--------------------------------
	// 位置の取得
	//--------------------------------
	VECTOR ap = a.GetPos();
	VECTOR bp = b.GetPos();

	//--------------------------------
	// 距離の計算
	//--------------------------------
	float dx = ap.x - bp.x;
	float dz = ap.z - bp.z;

	// 距離の計算（2D）
	float dist = sqrtf(dx * dx + dz * dz);

	// 当たり判定
	return dist < (a.GetRadius() + b.GetRadius());
}

//====================================
// 押し出し
//====================================
void Collsion::PushBack(Character& a, const Character& b)
{
	//--------------------------------
	// 位置の取得
	//--------------------------------
	VECTOR ap = a.GetPos();
	VECTOR bp = b.GetPos();

	//--------------------------------
	// 距離の計算
	//--------------------------------
	VECTOR push = VSub(ap, bp);

	// 2D距離の計算
	float dist = VSize(push);
	// 2D距離がほぼ0の場合は押し出さない
	if (dist <= 0.001f) return;

	// 2つのカプセルの半径の合計
	float totalRadius = a.GetRadius() + b.GetRadius();

	// 2D距離が半径の合計以上の場合は押し出さない
	if (dist >= totalRadius) return;

	//--------------------------------
	// 正規化
	//--------------------------------

	push = VNorm(push);

	//--------------------------------
	// めり込み量
	//--------------------------------

	float overlap = totalRadius - dist;

	//--------------------------------
	// 押し出し
	//--------------------------------

	// 位置の計算
	ap = VAdd(ap, VScale(push, overlap));
	// 位置の設定
	a.SetPos(ap);
}