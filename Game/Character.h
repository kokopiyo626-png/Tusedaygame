#pragma once
#include"DxLib.h"

class Character
{
	//============================================
	// カプセルを持つキャラクター
	//============================================
private:
	VECTOR pos;

	//半径と高さ
	float radius;
	float height;

	unsigned int color;

public:
	//コンストラクタ
	Character();
	//初期化
	void Init(VECTOR startPos, float r, float h, unsigned intc);
	//更新
	void Update();
	//描画
	void Draw();
	//キャラクターの位置を取得
	VECTOR GetPos() const { return pos; }
	//キャラクターの位置を設定
	void SetPos(VECTOR p) { pos = p; }
	//カプセルの半径を取得
	float GetRadius()const { return radius; }
	//カプセルの高さを取得
	float GetHeight()const { return height; }

	//カプセルの上端
	VECTOR GetCapsuleTop()const;
	//カプセルの下端
	VECTOR GetCapsuleBottom()const;

};

