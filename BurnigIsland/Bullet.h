#pragma once

class Bullet {
private:
	double _posX, _posY;
	double _movementX, _movementY;
	bool _liveFlag;

	int _gh_demonBullet;
	int _demonBullet_width;
	int _demonBullet_height;

public:
	Bullet();
	void Init();
	void Update();
	void Draw();
	void All();
	void SetTarget(int posX,int posY,int target_posX,int target_posY);
	void Deth();

	// 判定関数

	// 拠点と当たっているか
	bool BaseHitCheck();

	// Get関数

	// 生きているか
	bool GetLiveFlag();

private:
	void Move();
};