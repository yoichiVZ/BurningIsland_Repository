#pragma once

#include "YugudorasiruParticle.h"

class Island {
private:
	enum IslandState {
		GRASS,
		FIRE,
		BURN,
	};
	IslandState _islandState;

	int _posX, _posY;
	int _width, _height;
	int _rotation;
	bool _distanseFlag;
	bool _playerStayFlag;
	int _myNumber;
	int _fireCount, _burnCount;
	bool _fireStartFlag;
	int _fireStartCount;
	bool _extinguishedFlag;
	int _nowChoiceDistance;
	int _nowChoiceDistanceCount;
	bool _nowChoiceFlag;

	int _gh_island;
	int _gh_burnIsland;
	int _gh_base;
	int _base_width, _base_height;
	int _gh_base_crystal;
	
	int _gh_rightEfect01;

	int _gh_burningIsland[10];
	int _animPos_burningIsland;
	int _animCount_burningIslnad;

	int _gh_revivalingIsland[8];
	int _animPos_revivalingIsland;
	int _animCount_revivalingIsland;

	int _sh_fire;

	int _particle_activeCount;
	int _particle_firstActiveCount;

	YugudorasiruParticle* _yugudorasiruParticle[YUGUDORASIRU_PARITCLE_NUM];

public:
	int _gameOverFlag;

	Island();
	~Island();
	void Init();
	void Update();
	void Draw();
	void All();
	// ロープが繋げる範囲内か
	bool DistanseCheck(int px, int py);
	// プレイヤーが島にいるか
	bool PlayerStayCheck(int px, int py);
	// 移動できる範囲内か
	bool EnemyDistanseCheck(int ex, int ey);
	// エネミーが島にいるか
	bool EnemyStayCheck(int ex, int ey);
	void CrossCheck(Island* island);
	void GetMyNumber(int num);
	// 引火
	void Burning();
	// 着火
	void Ignition();
	// 座標セット
	void SetPosition(int posX, int posY);
	// 島復活
	void Revival();

	// 島の状態はGRASSか
	bool StateCheck_GRASS();
	// 島の状態はFIREか
	bool StateCheck_FIRE();
	// 島の状態はBURNか
	bool StateCheck_BURN();
	// 鎮火したか
	bool ExtinguishedCheck();

	// 以下 Get関数
	int GetPosX();
	int GetPosY();
	int GetWidth();
	int GetHeight();
	int GetFireStartflag();

	void MoveX(int num);
	void MoveY(int num);
};