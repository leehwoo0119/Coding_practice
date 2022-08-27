#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M = 0;
int map[1001][1001];
bool visited[1001][1001];

//»óÇÏÁÂ¿ì
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

queue<pair<int, int>>q;

int days[1001][1001];
int maxDays = 0;

void Bfs()
{
	while (!q.empty())
	{
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int next_y = cur_y + dy[dir];
			int next_x = cur_x + dx[dir];

			if (next_y >= 0 && next_y < N &&
				next_x >= 0 && next_x < M)
			{
				if (!visited[next_y][next_x] && map[next_y][next_x] == 0)
				{
					q.push(make_pair(next_y, next_x));
					visited[next_y][next_x] = true;
					map[next_y][next_x] = 1;
					days[next_y][next_x] = days[cur_y][cur_x] + 1;
					maxDays = max(maxDays, days[next_y][next_x]);
				}
			}
		}
	}
}

int main()
{
	cin >> M >> N;
	memset(map, -1, sizeof(map));	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}
	Bfs();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				maxDays = -1;
				break;
			}
		}
	}

	cout << maxDays;
	
}