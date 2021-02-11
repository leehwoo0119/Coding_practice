#include"Logic.h"

Logic::Logic()
{	
	cin >> gamemode;
	// gamemode 1 ���� 2 ������
	size = (gamemode == 1) ? 16 : 8;
	if (dat == NULL)
	{
		dat = (int**)new int* [size];

		for (int i = 0; i < size; i++)
		{
			dat[i] = (int*)new int[size];
			memset(dat[i], 0, sizeof(int) * size);
		}
		if (gamemode == 2)//������
		{
			//�ʱ� �ٵϾ�
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


