#pragma once

//プレイヤーオブジェクト
class Player;

class Camera 
{
public:
	void Update(const Player& player) const;
};

