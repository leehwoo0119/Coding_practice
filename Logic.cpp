#include"Logic.h"

void Logic::MakeMemory()
{	
	// gamemode 1 ¿À¸ñ 2 ¿Àµ¨·Î 3 ºù°í
	size = (gamemode == 1) ? 16 : (gamemode == 2) ? 8 : 5;
	if (dat == NULL)
	{
		dat = (int**)new int* [size];

		for (int i = 0; i < size; i++)
		{
			dat[i] = (int*)new int[size];
			memset(dat[i], 0, sizeof(int) * size);
		}
		if (gamemode == 2)//¿Àµ¨·Î
		{
			//ÃÊ±â ¹ÙµÏ¾Ë
			dat[3][3] = 2, dat[4][4] = 2;
			dat[3][4] = 1, dat[4][3] = 1;
		}
	}
}
Logic::~Logic()
{
	if (dat != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] dat[i];
		}
		delete[] dat;
	}
}


