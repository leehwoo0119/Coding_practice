#include "RenderWide.h"

void RenderWide::printBoard()
{
	Size = size;
	if (size == 10)
	{
		Size /= 2;
		DrawBingoTop();
	}
	else printUITop();
	DrawHorz(2, 3, 4, 0, 0);

	for (int i = 0; i < Size; i++)
	{
		DrawHorz(1, 1, 1, 1, i);
		if (i == Size - 1)break;
		DrawHorz(5, 6, 7, 0, i + 1);
	}
	DrawHorz(8, 9, 10, 0, Size - 1);

}

void RenderWide::DrawHorz(int L, int M, int R, int S, int i)
{

	for (int t = ((Size == 5) ? 0 : 1); t <= 1; t++)
	{
		cout << line[L];

		for (int j = 0; j <= Size; j++)
		{
			if (S == 0)cout << line[S];
			//ºù°í 1p
			else  if (t == 0)cout << GetStone(i, j);
			//ºù°í 2p
			else  if (t == 1 && Size == 5)cout << GetStone(i , j + 5);
			//¿Àµ¨·Î
			else if (t == 1 && Size == 8)cout << GetStone(i, j);
			if (j == Size - 1)break;
			cout << line[M];
		}
		cout << line[R];

		if (S != 0 && Size != 5)cout << i;

	}
	cout << endl;
}

string RenderWide::GetStone(int y, int x)
{
	string res = "  ";

	if (Size == 5)
	{
		res = "";
		if (dat[y][x] != 1 && dat[y][x] != 2)DrawBingo(y, x);
		else
		{
			if (x < 5)res = stone[0];
			if (x >= 5)res = stone[1];
		}
	}
	else 
		if (dat[y][x] != 0)res = stone[dat[y][x] - 1];

	return res;
}

void RenderWide::printUITop()
{
	for (int i = 0; i < size; i++) cout << "   " << i;
	cout << endl;
}