#include "LogicOthello.h"

void LogicOthello::analyzeGame(int y, int x, int dir)
{
	if (dat[y][x] == 0) return;
	if (dat[y][x] != 3 - turn && dat[y][x] != 0)
		othelloCnt++;

	switch (dir)
	{
	case RIGHT:
		if (dat[y][x] == 3 - turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y, x - i);
		analyzeGame(y, x + 1, dir);
		break;
	case LEFT:
		if (dat[y][x] == 3 - turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y, x + i);
		analyzeGame(y, x - 1, dir);
		break;
	case UP:
		if (dat[y][x] == 3 - turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y + i, x);
		analyzeGame(y - 1, x, dir);
		break;
	case DOWN:
		if (dat[y][x] == 3 - turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y - i, x);
		analyzeGame(y + 1, x, dir);
		break;
	case DR:
		if (dat[y][x] == 3 - turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y - i, x - i);
		analyzeGame(y + 1, x + 1, dir);
		break;
	case UL:
		if (dat[y][x] == 3 - turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y + i, x + i);
		analyzeGame(y - 1, x - 1, dir);
		break;
	case DL:
		if (dat[y][x] == 3 - turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y - i, x + i);
		analyzeGame(y + 1, x - 1, dir);
		break;
	case UR:
		if (dat[y][x] == 3 - turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y + i, x - i);
		analyzeGame(y - 1, x + 1, dir);
		break;
	}
}
void LogicOthello::Cal(int y, int x)
{
	dat[y][x] = 3 - turn;
	isStone = true;
}

