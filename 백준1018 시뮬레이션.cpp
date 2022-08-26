#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M = 0;
int map[51][51];
int minCnt = 65;

int chess_1[8][8] = { {1,2,1,2,1,2,1,2},
					  {2,1,2,1,2,1,2,1},
					  {1,2,1,2,1,2,1,2},
					  {2,1,2,1,2,1,2,1},
					  {1,2,1,2,1,2,1,2},
					  {2,1,2,1,2,1,2,1},
					  {1,2,1,2,1,2,1,2},
					  {2,1,2,1,2,1,2,1} };

int chess_2[8][8] = { {2,1,2,1,2,1,2,1},
					  {1,2,1,2,1,2,1,2},
					  {2,1,2,1,2,1,2,1},
					  {1,2,1,2,1,2,1,2},
					  {2,1,2,1,2,1,2,1},
					  {1,2,1,2,1,2,1,2},
					  {2,1,2,1,2,1,2,1},
					  {1,2,1,2,1,2,1,2} };

void Solve(int _start_y, int _start_x)
{
	int cntChess_1 = 0;
	int cntChess_2 = 0;

	for (int i = _start_y, chess_i = 0; i < _start_y + 8; i++, chess_i++)
	{
		for (int j = _start_x, chess_j = 0; j < _start_x + 8; j++, chess_j++)
		{
			if (map[i][j] != chess_1[chess_i][chess_j])cntChess_1++;
			if (map[i][j] != chess_2[chess_i][chess_j])cntChess_2++;
		}
	}

	minCnt = min(minCnt, cntChess_1);
	minCnt = min(minCnt, cntChess_2);
}

int main() 
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char input;
			cin >> input;
			if (input == 'W')map[i][j] = 1;
			else if (input == 'B')map[i][j] = 2;
		}
	}

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			Solve(i, j);
		}
	}
	cout << minCnt;
}