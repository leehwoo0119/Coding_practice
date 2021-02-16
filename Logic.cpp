#include"Logic.h"

void Logic::MakeMemory()
{	
	// gamemode 1 ¿À¸ñ 2 ¿Àµ¨·Î 3 ºù°í
	size = (gamemode == 1) ? 16 : (gamemode == 2) ? 8 : (5 * 2);
	if (dat == NULL)
	{
		Size = (gamemode == 3) ? size / 2 : size;
		dat = (int**)new int* [Size];

		for (int i = 0; i < Size; i++)
		{
			dat[i] = (int*)new int[size];
			memset(dat[i], 0, sizeof(int) * size);
		}
		GameTypeMemoryMake();
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


