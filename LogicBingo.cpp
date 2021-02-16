#include "LogicBingo.h"

void LogicBingo::analyzeGame(int y, int x, int _y, int _x)
{

	isStone = true;

	if (dat[y][x] == dat[_y][_x])bingoCnt++;
	if (bingoCnt == 4)cout << "승리하는 메소드로"<<endl;
}

void LogicBingo::GameTypeMemoryMake()
{
	while (1)
	{
		bingoNum = rand() % 25 + 3;

		for (int i = 0; i <= cnt; i++)
		{
			if (cnt == 0)
			{
				numArr[cnt] = bingoNum;
				break;
			}
			else if (bingoNum == numArr[i])
			{
				cnt--;
				break;
			}
			else if (i == cnt)numArr[cnt] = bingoNum;

		}
		cnt++;
		if (cnt == 25)break;
	}
	int t = 0;
	for (int i = 0; i < size / 2; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (player == 1 && j < 5)
				dat[i][j] = numArr[t++];
			else if (player == 2 && j >= 5)
				dat[i][j] = numArr[t++];
		}
	}
	MemSet();
	if (player == 1)
	{
		player = 2;
		GameTypeMemoryMake();
	}
}
void LogicBingo::MemSet()
{
	cnt = 0;
	bingoNum = 0;
	memset(numArr, 0, sizeof(int) * 25);
}