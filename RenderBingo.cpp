#include "RenderBingo.h"

void RenderBingo::DrawBingo(int y, int x)
{
	cout << dat[y][x] - 2;
	//dat�� ���� 2~27������
	if (dat[y][x] < 10 + 2)cout << " ";
}

void RenderBingo::DrawBingoTop()
{
	cout << "1P                    2P" << endl;
}
