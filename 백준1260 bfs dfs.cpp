#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M = 0;
vector<int>map[10002];
bool visited[1002];

void Dfs(int _start)
{
	visited[_start] = true;
	cout << _start << ' ';
	
	for(int i=0;i< map[_start].size(); i++)
	{
		int n = map[_start][i];
		if (!visited[n])
		{
			Dfs(n);
		}		
	}

}

void Bfs(int _start)
{
	queue<int>q;	
	q.push(_start);
	visited[_start] = true;

	while (!q.empty())
	{
		int start = q.front();
		q.pop();
		cout << start << ' ';

		for (auto x : map[start])
		{
			if (!visited[x])
			{
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main()
{
	int start = 0;
	cin >> N >> M >> start;

	for (int i = 0; i < M; i++)
	{
		int input_1, input_2 = 0;
		cin >> input_1 >> input_2;
		map[input_1].push_back(input_2);
		map[input_2].push_back(input_1);
	}
	
	for (int i = 1; i <= N; i++)
	{
		sort(map[i].begin(), map[i].end());
	}

	Dfs(start);
	memset(visited, false, sizeof(visited));
	cout << "\n";
	Bfs(start);
}