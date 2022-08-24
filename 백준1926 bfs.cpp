// 코드 참고 : https://github.com/ndb796/python-for-coding-test

#include <iostream>
#include <queue>
using namespace std;

int n, m = 0;
int maxCnt, maxArea = 0;
int map[501][501];
bool check[501][501];

//상하좌우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int _start_Y, int _start_X)
{
	int curCnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(_start_Y, _start_X));
	check[_start_Y][_start_X] = true;

	while (!q.empty())
	{
		int start_Y = q.front().first;
		int start_X = q.front().second;
		q.pop();
		curCnt++;

		for (int dir = 0; dir < 4; dir++)
		{
			int next_Y = start_Y + dy[dir];
			int next_X = start_X + dx[dir];

			if (next_Y >= 0 && next_Y < n &&
				next_X >= 0 && next_X < m)
			{
				if (!check[next_Y][next_X] &&
					map[next_Y][next_X] == 1)
				{				
					q.push(make_pair(next_Y, next_X));
					check[next_Y][next_X] = true;
				}
			}
		}
	}
	maxArea = max(maxArea, curCnt);
}

int main(void) 
{
	cin >> n >> m;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			int input = 0;
			cin >> input;
			map[y][x] = input;
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (!check[y][x] && map[y][x] == 1)
			{
				bfs(y, x);
				maxCnt++;
			}
		}
	}
	cout << maxCnt << "\n" << maxArea;
	return 0;
}