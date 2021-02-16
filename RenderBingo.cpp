#include "RenderBingo.h"

void RenderBingo::DrawBingo()
{
	bingoNum = rand() % 25 + 1;

	for (int i = 0; i <= cnt; i++)
	{
		if (i == cnt && bingoNum != numArr[i])
		{
			numArr[cnt++] = bingoNum;
			break;
		}
		if (bingoNum == numArr[i])
		{
			bingoNum = rand() % 25 + 1;
			i = 0;
		}
		if (i == 25)break;
	}

	if (bingoNum < 10)cout << " ";
	cout << bingoNum;
}

void RenderBingo::DrawBingoTop()
{
	cout << "1P                    2P" << endl;
}
