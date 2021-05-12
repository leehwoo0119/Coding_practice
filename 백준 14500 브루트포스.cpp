#include<iostream>
#include <algorithm>
using namespace std;

int arr[501][501] = { 0, };
int visited[501][501] = { 0, };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int Vertical, horizontal;


int dfs(int y, int x, int dep)
{
	if (dep == 4)return arr[y][x];

	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && nx >= 0 && ny < Vertical && nx < horizontal)
		{
			if (arr[ny][nx] != 0 && visited[ny][nx] == 0)
			{
				//cout<<y<<' '<<x<<' '<<ny<<' '<<nx<<endl;
				visited[ny][nx] = 1;
				sum = max(sum, arr[y][x] + dfs(ny, nx, dep + 1));
				visited[ny][nx] = 0;
			}
		}
	}
	return sum;
}

int Exception_Case(int y, int x)
{
	int sum = 0;
	//ㅏ
	//if (y >= 0 && y < Vertical - 3 && x >= 0 && x < horizontal - 1)
	{
		sum = max(sum, arr[y][x] + arr[y - 1][x] + arr[y - 1][x + 1] + arr[y - 2][x]);
	}
	//ㅓ
	//if (y >= 0 && y < Vertical - 3 && x >= 1 && x < horizontal)
	{
		sum = max(sum, arr[y][x] + arr[y - 1][x] + arr[y - 1][x - 1] + arr[y - 2][x]);
	}
	//ㅗ
	//if (y >= 1 && y < Vertical && x >= 1 && x < horizontal - 1)
	{
		sum = max(sum, arr[y][x] + arr[y - 1][x] + arr[y - 1][x - 1] + arr[y - 1][x + 1]);
	}
	//ㅜ
	//if (y >= 0 && y < Vertical - 1 && x >= 1 && x < horizontal - 1)
	{
		sum = max(sum, arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 1][x + 1]);
	}
	return sum;
}

int main() {

	//세로 가로

	int ans = 0;
	cin >> Vertical >> horizontal;

	for (int i = 0; i < Vertical; i++)
	{
		for (int j = 0; j < horizontal; j++)
		{
			int input = 0;
			cin >> input;
			arr[i][j] = input;
		}
	}

	for (int i = 0; i < Vertical; i++)
	{
		for (int j = 0; j < horizontal; j++)
		{
			visited[i][j] = 1;
			ans = max(ans, dfs(i, j, 1));
			//cout<<ans<<'\n';
			ans = max(ans, Exception_Case(i, j));
			visited[i][j] = 0;
		}
	}
	cout << ans;
	return 0;
}