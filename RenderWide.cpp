#include "RenderWide.h"


void RenderWide::printBoard()
{
	printUITop();
	DrawHorz(2, 3 , 4 , 0, 0);
	
	for (int i = 0; i < size; i++)
	{
			DrawHorz(1, 1, 1, 1, i);
		if (i == size - 1)break;
		DrawHorz(5, 6 , 7 , 0, i + 1);
	}
	DrawHorz(8, 9 , 10, 0, size - 1);
}

void RenderWide::DrawHorz(int L, int M, int R, int S, int i)
{
	cout << line[L];

	for (int j = 0; j <= size; j++)
	{
			if (S == 0)cout << line[S];
			else  cout << GetStone(i, j);
			if (j == size - 1)break;
			cout << line[M];
	}
	cout << line[R];

	if (S != 0)cout << i;

	cout << endl;
}
string RenderWide::GetStone(int y, int x)
{
	string res = "  ";
	if (dat[y][x] != 0)res = stone[dat[y][x] - 1];
	return res;
}
void RenderWide::printUITop()
{
	cout << "   0   1   2   3   4   5   6   7" << endl;
}