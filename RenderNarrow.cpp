#include "RenderNarrow.h"

void RenderNarrow::printBoard()
{
	printUITop();
	DrawHorz(2, 3, 4 , 0, 0);	
	for (int i = 0; i < size; i++)
	{
		if (i == size - 2)
			break;

		DrawHorz(5, 6, 7, 0, i + 1);
	}
	DrawHorz(8, 9, 10, 0, size - 1);
}
void RenderNarrow::DrawHorz(int L, int M, int R, int S, int i)
{
	cout << line[L];
	
	for (int j = 1; j <= size; j++)
	{
			if (j == size - 2)break;
			if (dat[i][j] != 0)
				cout << GetStone(i, j);
			else
				cout << line[M];
	}
	cout << line[R];

		if (i < 10)
			cout << ' ' << i;
		else
			cout << ' ' << (char)((char)i + 'a' - 10);
	cout << endl;
}
string Render::GetStone(int y, int x)
{
	string res = "";
	if (dat[y][x] != 0)res = stone[dat[y][x] - 1];
	return res;
}
void RenderNarrow::printUITop()
{
		cout << "0 1 2 3 4 5 6 7 8 9 a b c d e f" << endl;
}
