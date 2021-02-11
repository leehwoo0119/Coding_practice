#include "Logic2D.h"

bool Logic2D::setData(int _r, int _c)
{
	if (dat[_r][_c] > 0)return false;

	dat[_r][_c] = turn;
	turn = 3 - turn;

	for (int dir_ = 0; dir_ < 8; dir_++)
	{
		if (gamemode == 1)analyzeOmok(_r, _c, dir_);
		//else analyzeOthello(_r, _c, dir_);
	}

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
