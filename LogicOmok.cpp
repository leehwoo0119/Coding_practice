#include "LogicOmok.h"

void LogicOmok::analyzeGame(int y, int x, int _y, int _x)
{
	isStone = true;

	if (dat[y][x] == dat[_y][_x])omokCnt++;
	if (omokCnt == 4)cout << "�¸��ϴ� �޼ҵ��";
}
