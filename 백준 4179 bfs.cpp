#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M = 0;
char map[1001][1001];
bool peopleVisited[1001][1001];
bool fireVisited[1001][1001];

//»óÇÏÁÂ¿ì
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int peopleDays[1001][1001];
int fireDays[1001][1001];

queue<pair<pair<int, int>, int>>q_people;
queue<pair<int, int>>q_fire;

bool bFlag = false;
bool bFireNone = false;

int days = 0;

void People_Bfs()
{
	while (!q_people.empty())
	{
		int cur_y = q_people.front().first.first;
		int cur_x = q_people.front().first.second;
		days = q_people.front().second;
		q_people.pop();

		if (cur_y == N - 1 || cur_x == M - 1 || cur_y == 0 || cur_x == 0)
		{
			bFlag = true;
			return;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int next_y = cur_y + dy[dir];
			int next_x = cur_x + dx[dir];

			if (next_y >= 0 && next_y < N &&
				next_x >= 0 && next_x < M)
			{
				if (!peopleVisited[next_y][next_x])
				{
					if (map[next_y][next_x] != '#')
					{
						if (((days + 1) < fireDays[next_y][next_x]) || bFireNone)
						{
							q_people.push(make_pair(make_pair(next_y, next_x), days + 1));
							peopleVisited[next_y][next_x] = true;
							peopleDays[next_y][next_x] = peopleDays[cur_y][cur_x] + 1;
						}					
					}
				}
			}
		}
	}
}

void Fire_Bfs()
{
	if (q_fire.empty())
	{
		bFireNone = true;
		return;
	}

	while (!q_fire.empty())
	{
		int cur_y = q_fire.front().first;
		int cur_x = q_fire.front().second;
		q_fire.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int next_y = cur_y + dy[dir];
			int next_x = cur_x + dx[dir];

			if (next_y >= 0 && next_y < N &&
				next_x >= 0 && next_x < M)
			{
				if (!fireVisited[next_y][next_x])
				{
					if (map[next_y][next_x] != '#')
					{
						q_fire.push(make_pair(next_y, next_x));
						fireVisited[next_y][next_x] = true;
						fireDays[next_y][next_x] = fireDays[cur_y][cur_x] + 1;
					}
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
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'J')
			{
				q_people.push(make_pair(make_pair(i, j), 0));
				peopleVisited[i][j] = true;
			}
			else if (map[i][j] == 'F')
			{
				q_fire.push(make_pair(i, j));
				fireVisited[i][j] = true;
			}
		}
	}
	Fire_Bfs();
	People_Bfs();

	
	if (bFlag)cout << days + 1;
	else cout << "IMPOSSIBLE";
}






































































































































































































































































































































































