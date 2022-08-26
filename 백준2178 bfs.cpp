#include <iostream>
#include <queue>

using namespace std;




//상하좌우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M = 0;
int map[101][101];
bool check[101][101];
int dist[101][101];

// 미로 경로 탐색
void bfs(int _start_y, int _start_x) 
{
	queue<pair<int, int> > q;
	check[_start_y][_start_x] = true;
	q.push(make_pair(_start_y, _start_x));
	dist[_start_y][_start_x]++;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int next_y = y + dy[dir];
			int next_x = x + dx[dir];

			if (next_y >= 0 && next_y < N &&
				next_x >= 0 && next_x < M)
			{
				if (!check[next_y][next_x] && map[next_y][next_x] == 1)
				{
					check[next_y][next_x] = true;
					q.push(make_pair(next_y, next_x));
					dist[next_y][next_x] = dist[y][x] + 1;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			map[i][j] = s[j] - '0';
		}
	}

	bfs(0, 0);
	cout << dist[N - 1][M - 1];
}