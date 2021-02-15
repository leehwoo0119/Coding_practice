#include "LogicOmok.h"

void LogicOmok::analyzeGame(int y, int x, int _y, int _x)
{
	//cout << y<<" "<< x << "," << _y << " " << _x << "," << omokCnt << endl;
	isStone = true;

	if (dat[y][x] == dat[_y][_x])omokCnt++;
	if (omokCnt == 4)cout << "승리하는 메소드로";
}
