#include <iostream>
#include <queue>
using namespace std;

int N, M = 0;
bool visited[1000001];
int answer = 0;

void Bfs(int _start)
{
	queue<pair<int, int>>q;
	q.push(make_pair(_start, 0));
	visited[_start] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (x == M)
		{
			answer = cost;
			break;
		}

		int x_1 = x - 1;
		int x_2 = x + 1;
		int x_3 = x * 2;
		
		if (x_1 >= 0 && !visited[x_1])
		{
			visited[x_1] = true;
			q.push(make_pair(x_1, cost + 1));
		}

		if (x_2 <= M && !visited[x_2])
		{
			visited[x_2] = true;
			q.push(make_pair(x_2, cost + 1));
		}

		if (x_3 <= M + 1 && !visited[x_3])
		{
			visited[x_3] = true;
			q.push(make_pair(x_3, cost + 1));
		}
	}
}
int main()
{
	cin >> N >> M;
	Bfs(N);

	cout << answer;
	return 0;
}



































































































































































































































































































































































