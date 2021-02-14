#include "LogicOmok.h"

void LogicOmok::analyzeGame(int y, int x, int dir)
{
	//cout << omokCnt << endl;
	isStone = true;
	if (dat[y][x] == 0) return;
	switch (dir)
	{
	case RIGHT:
		if (dat[y][x] == dat[y][x + 1])omokCnt++;
		analyzeGame(y, x + 1, dir);
		break;
	case LEFT:
		if (dat[y][x] == dat[y][x - 1])omokCnt++;
		analyzeGame(y, x - 1, dir);
		break;
	case UP:
		if (dat[y][x] == dat[y - 1][x])omokCnt++;
		analyzeGame(y - 1, x, dir);
		break;
	case DOWN:
		if (dat[y][x] == dat[y + 1][x])omokCnt++;
		analyzeGame(y + 1, x, dir);
		break;
	case DR:
		if (dat[y][x] == dat[y + 1][x + 1]) omokCnt++;
		analyzeGame(y + 1, x + 1, dir);
		break;
	case UL:
		if (dat[y][x] == dat[y - 1][x - 1]) omokCnt++;
		analyzeGame(y - 1, x - 1, dir);
		break;
	case DL:
		if (dat[y][x] == dat[y + 1][x - 1])omokCnt++;
		analyzeGame(y + 1, x - 1, dir);
		break;
	case UR:
		if (dat[y][x] == dat[y - 1][x + 1])omokCnt++;
		analyzeGame(y - 1, x + 1, dir);
		break;
	}
}
