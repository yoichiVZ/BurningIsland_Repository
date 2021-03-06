#include <DxLib.h>

#include "DrawNumber.h"

#include "MyDrawTurn.h"

DrawNumber::DrawNumber()
{
	int _vgh_killCount[10];
	LoadDivGraph("Resource\\Image\\rednumber.png", 10, 10, 1, 30, 50, _vgh_killCount);
	_gh_killCount[0] = _vgh_killCount[9];
	for (int i = 0; i < 9; i++) {
		_gh_killCount[i + 1] = _vgh_killCount[i];
	}

	int _vgh_wave[10];
	LoadDivGraph("Resource\\Image\\WAVEnumber2.png", 10, 10, 1, 40, 70, _gh_wave);
	//_gh_wave[0] = _vgh_wave[9];
	//for (int i = 0; i < 9; i++) {
	//	_gh_wave[i + 1] = _vgh_wave[i];
	//}

	LoadDivGraph("Resource\\Image\\ResultWAVEnumber2.png", 10, 10, 1, 80, 140, _gh_resultWave);

	LoadDivGraph("Resource\\Image\\WAVEnumber3.png", 10, 10, 1, 100, 170, _gh_waveUp);
}

void DrawNumber::Draw(int posX, int posY, int vol, int drawNum)
{
	int draw_gh[10];
	JudgSetNumber(draw_gh, drawNum);

	char buf[100];
	int num;

	num = sprintf_s(buf, "%d", vol);
	for (int i = 0; i < num; i++) {
		MyDrawTurn::Instance().SetDrawItem(posX + i * 30, posY, draw_gh[(buf[i] - '0')], _priority);
	}
}

void DrawNumber::DrawBright(int posX, int posY, int vol, int drawNum, int redBright, int greenBright, int blueBright, int BlendMode, int BlendParam)
{
	int draw_gh[10];
	JudgSetNumber(draw_gh, drawNum);

	char buf[100];
	int num;

	num = sprintf_s(buf, "%d", vol);
	for (int i = 0; i < num; i++) {
		MyDrawTurn::Instance().SetDrawBrightItem(posX + i * 30, posY, draw_gh[(buf[i] - '0')], _priority, redBright, greenBright, blueBright, BlendMode, BlendParam);
	}
}

void DrawNumber::JudgSetNumber(int draw_gh[10], int drawNum)
{
	switch (drawNum) {
	case SETDRAWNUM_KILLCOUNT:
		for (int i = 0; i < 10; i++) {
			draw_gh[i] = _gh_killCount[i];
		}
		_priority = 0.8f;
		break;
	case SETDRAWNUM_WAVE:
		for (int i = 0; i < 10; i++) {
			draw_gh[i] = _gh_wave[i];
		}
		_priority = 0.8f;
		break;
	case SETDRAWNUM_RESULTWAVE:
		for (int i = 0; i < 10; i++) {
			draw_gh[i] = _gh_resultWave[i];
		}
		_priority = 0.91f;
		break;
	case SETDRAWNUM_WAVEUP:
		for (int i = 0; i < 10; i++) {
			draw_gh[i] = _gh_waveUp[i];
		}
		_priority = 0.8f;
		break;
	default:
		break;
	}
}
