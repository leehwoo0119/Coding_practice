#include "LogicBingo.h"

void LogicBingo::analyzeGame(int y, int x, int _y, int _x)
{

	isStone = true;

	if (dat[y][x] == dat[_y][_x])bingoCnt++;
	if (bingoCnt == 4)cout << "�¸��ϴ� �޼ҵ��";
}
