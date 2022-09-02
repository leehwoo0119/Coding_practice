#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M = 0;
vector<int>map[101];
bool visited[101];

void Dfs(int _start)
{		
	for (int i = 0; i < map[_start].size(); i++)
	{
		int n = map[_start][i];
		if (!visited[n])
		{
			visited[_start] = true;
			Dfs(n);
		}			
	}	
}
int main()
{
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input = 0;
			cin >> input;

			if(input == 1)
				map[i].push_back(j);
		}	
	}
	for (int i = 0; i < N; i++)
	{
		Dfs(i);
		for (int j = 0; j < N; j++)
		{
			cout << visited[j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}


































































































































































































































































































































































