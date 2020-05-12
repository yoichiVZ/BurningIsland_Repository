#pragma once

#include "Island.h"
#include "Player.h"
#include "Rope.h"
#include "Enemy.h"
#include "Time.h"
#include "Bullet.h"

#include "IslandInfo.h"
#include "EnemyInfo.h"
#include "PlayerInfo.h"
#include "BulletInfo.h"
#include "RopeInfo.h"

//#define ISLAND_NUM 33
#define M_PI 3.14159265358979323846
#define FIRE_RELOAD_NUM 300

class GameController {
private:
	int _mouse_Left, _mousePosX_Left, _mousePosY_Left, _mouseCount_Left;
	int _mouse_Right, _mousePosX_Right, _mousePosY_Right, _mouseCount_Right;
	int _spaceKeyCount;
	int _fireReloadCount;
	bool _fireReloadFlag;
	int _enemyResponCount;
	bool _enemyResponFlag;
	int _killCount;
	int _totalKillCount;
	int _wave;
	int _remainingEnemyCount;
	int _onth_flag[4];

	int _gh_background;
	int _gh_background2;
	int _gh_cloud;
	int _gh_thunder[5];
	int _gh_thunderUI[6];
	int _gh_UIbar;
	int _gh_hp;
	int _gh_hp_damage;
	int _gh_tuta_life_active;
	int _gh_tuta_life_inactive;
	int _gh_tuta;
	int _gh_tuta_top;
	int _gh_tuta_middle;
	int _gh_tuta_fire_top;
	int _gh_tuta_fire_middle;
	int _background_width, _background_height;
	int _cloud_posX, _cloud_posY;
	int _cloud_width, _cloud_height;
	int _cloud_speed_count;
	int _thunder_width, _thunder_height;
	int _thunder_count[IslandInfo::Island_Num];
	int _animPos_thunder[IslandInfo::Island_Num];
	int _animPos_thunderUI;
	int _tuta_width, _tuta_height;
	int _tuta_top_posX, _tuta_top_posY;
	int _tuta_top_width, _tuta_top_height;
	int _tuta_middle_width, _tuta_middle_height;

	int _island_posX_data[IslandInfo::Island_Num];
	int _island_posY_data[IslandInfo::Island_Num];
	int _nowIsland;
	int _now_player_num;

	int _sh_gameplay;
	int _sh_thunder;

	int s_count;
	int right_count;
	int left_count;
	int up_count;
	int down_count;

	Island* _island[IslandInfo::Island_Num];
	Player _player;
	Rope _rope;
	Enemy* _enemy[EnemyInfo::Enemy_Num];
	Time _time;
	Bullet* _bullet[BulletInfo::Bullet_Num];

	enum Scenetate {
		TITLE,
		TUTORIAL,
		GAMEPLAY,
		RESULT
	};
	Scenetate _sceneState;

public:
	GameController();
	~GameController();
	void Init();
	void All();

private:
	void Title();
	void Tutorial();
	void GamePlay();
	void Result();
	void Draw();
	int OnMouseButtonLeft();
	int OnMouseButtonRight();
	int OnSpaceButton();
	int LengthCheck(int posX1, int posY1, int posX2, int posY2);
	void EnemySpawn();
	void PositionSave();
	void PositionLoad();
};