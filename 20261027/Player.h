#pragma once

class Player 
{
private:
	float x;
	float y;
	float z;

public:
	///<summary>
	///コンストラクタ
	/// </summary>
	Player();

	///<summary>
	///プレイヤー更新
	/// </summary>
	/// <param name="deltaTime">フレームレート</param>
	void Update(float deltaTime);

	///<summary>
	///プレイヤー描画
	/// </summary>
	void Draw() const;

	//プレイヤーの位置を取得
	float GetX() const;
	float GetY() const;
	float GetZ() const;

};
