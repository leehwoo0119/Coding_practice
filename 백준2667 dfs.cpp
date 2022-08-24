
#include <iostream>
#include <vector>
using namespace std;

int n = 0;
int map[26][26];
bool check[26][26];
int curCnt = 1;

//»óÇÏÁÂ¿ì
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

vector<int>v;

void Dfs(int _start_Y, int _start_X)
{
	check[_start_Y][_start_X] = true;

	for (int dir = 0; dir < 4; dir++)
	{
		int next_Y = _start_Y + dy[dir];
		int next_X = _start_X + dx[dir];

		if (next_Y >= 0 && next_Y < n &&
			next_X >= 0 && next_X < n)
		{
			if (!check[next_Y][next_X] && map[next_Y][next_X] == 1)
			{
				check[next_Y][next_X] = true;
				curCnt++;
				Dfs(next_Y, next_X);
			}
		}
	}
}

int main(void) 
{
	string input;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = input[j] - '0';
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!check[y][x] && map[y][x] == 1)
			{
				curCnt = 1;
				Dfs(y, x);
				v.push_back(curCnt);
			}
		}
	}

	cout << v.size() << "\n";

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
	return 0;
}