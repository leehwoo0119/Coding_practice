#include "Logic2D.h"

bool Logic2D::setData(int _r, int _c)
{
	if (dat[_r][_c] > 0)return false;

	isStone = false;

	dat[_r][_c] = turn;

	for (int dir_ = 0; dir_ < 8; dir_++)
	{		
		analyzeGame(_r, _c, dir_);
		othelloCnt = 0;
	}
	
	if (!isStone)
	{
		dat[_r][_c] = 0;
		return false;
	}

	turn = 3 - turn;

	return false;
}

bool Logic2D::inputData(string input)
{
	int v = (int)input[0];
	int _r = (v < 'a') ? v - '0' : v - 'a' + 10;

	v = (int)input[1];
	int _c = (v < 'a') ? v - '0' : v - 'a' + 10;
	return setData(_r, _c);
}
