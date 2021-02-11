#include "LogicOmok.h"

void LogicOmok::analyzeOmok(int y, int x, int dir)
{
	//cout << omokCnt << endl;
	if (dat[y][x] == 0) return;
	switch (dir)
	{
	case RIGHT:
		if (dat[y][x] == dat[y][x + 1])omokCnt++;
		analyzeOmok(y, x + 1, dir);
		break;
	case LEFT:
		if (dat[y][x] == dat[y][x - 1])omokCnt++;
		analyzeOmok(y, x - 1, dir);
		break;
	case UP:
		if (dat[y][x] == dat[y - 1][x])omokCnt++;
		analyzeOmok(y - 1, x, dir);
		break;
	case DOWN:
		if (dat[y][x] == dat[y + 1][x])omokCnt++;
		analyzeOmok(y + 1, x, dir);
		break;
	case DR:
		if (dat[y][x] == dat[y + 1][x + 1]) omokCnt++;
		analyzeOmok(y + 1, x + 1, dir);
		break;
	case UL:
		if (dat[y][x] == dat[y - 1][x - 1]) omokCnt++;
		analyzeOmok(y - 1, x - 1, dir);
		break;
	case DL:
		if (dat[y][x] == dat[y + 1][x - 1])omokCnt++;
		analyzeOmok(y + 1, x - 1, dir);
		break;
	case UR:
		if (dat[y][x] == dat[y - 1][x + 1])omokCnt++;
		analyzeOmok(y - 1, x + 1, dir);
		break;
	}
}
