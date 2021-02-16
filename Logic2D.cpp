#include "Logic2D.h"

bool Logic2D::setData(int _r, int _c)
{
	if (gamemode != 3 && dat[_r][_c] > 0)return false;

	isStone = false;
	
	if (gamemode != 3)
	{
		dat[_r][_c] = turn;
		LogicDir(_r, _c);
	}		
	else
	{
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < size; j++)
				if (dat[i][j] == 2 + (_r * 10) + _c)
				{
					dat[i][j] = turn;
					LogicDir(i, j);
				}						
		}
	}
	
	omokCnt = 0;
	bingoCnt = 0;
	if (!isStone)
	{
		dat[_r][_c] = 0;
		return false;
	}

	turn = 3 - turn;

	return false;
}
void Logic2D::LogicDir(int y, int x)
{
	for (int dir_ = 0; dir_ < 8; dir_++)
	{
		gameLogic(dir_, y, x);
		othelloCnt = 0;
	}
}
void Logic2D::gameLogic(int dir, int y, int x)
{
	int _turn = (gamemode == 1) ? turn : 3 - turn;
	for (int _y = y, _x = x;
		(0 <= _y && _y < Size) && (0 <= _x && _x < size);
		_y += move[dir][0], _x += move[dir][1])
	{
		if (_y == y && _x == x)continue;	
		if (dat[_y][_x] != _turn && dat[_y][_x] != 0) {
			othelloCnt++;
		}	
		analyzeGame(y, x, _y, _x);
		if (dat[_y][_x] == 0)break;
	}

}



bool Logic2D::inputData(string input)
{
	int v = (int)input[0];
	int _r = (v < 'a') ? v - '0' : v - 'a' + 10;
	v = (int)input[1];
	int _c = (v < 'a') ? v - '0' : v - 'a' + 10;
	if ((int)input[1] == NULL)
	{
		_c = _r;
		_r = 0;
	}
	return setData(_r, _c);
}
