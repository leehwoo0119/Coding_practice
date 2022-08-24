
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n = 0;
int map[26][26];
bool check[26][26];
int curCnt = 1;

//»óÇÏÁÂ¿ì
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

vector<int>v;

void Bfs(int _start_Y, int _start_X)
{
	queue<pair<int, int>>q;
	q.push(make_pair(_start_Y, _start_X));
	check[_start_Y][_start_X] = true;

	while (!q.empty())
	{
		int start_Y = q.front().first;
		int start_X = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int next_Y = start_Y + dy[dir];
			int next_X = start_X + dx[dir];

			if (next_Y >= 0 && next_Y < n &&
				next_X >= 0 && next_X < n)
			{
				if (!check[next_Y][next_X] && map[next_Y][next_X] == 1)
				{
					q.push(make_pair(next_Y, next_X));
					check[next_Y][next_X] = true;
					curCnt++;				
				}
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
				Bfs(y, x);
				v.push_back(curCnt);
			}
		}
	}

	cout << v.size() << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
	return 0;
}