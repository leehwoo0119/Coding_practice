#include "LogicOthello.h"

void LogicOthello::analyzeGame(int y, int x, int _y, int _x)
{
	int yi = 0, xi = 0;
	if (_x > x)xi = 1;
	else if (_x < x)xi = -1;
	if (_y > y)yi = 1;
	else if (_y < y)yi = -1;

	if (dat[_y][_x] == 3 - turn && othelloCnt != 0)
		for (int i = 0; i <= othelloCnt; i++)
			Cal(y + (yi)*i, x + (xi)*i);
}
void LogicOthello::Cal(int y, int x)
{
	dat[y][x] = 3 - turn;
	isStone = true;
}

