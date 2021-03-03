#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int N = 0, M = 0;

	cin >> N;
	cin >> M;
	vector<int>v(N);
	int v1 = 0, v2 = 0, v3 = 0;
	auto it = v.begin();


	for (int i = 0; i < M; i++)
	{
		cin >> v1; cin >> v2; cin >> v3;
		//v1째부터 v2까지 v3로 채운다 
		fill(it + v1 - 1, it + v2, v3);
	}

	for (int x : v)
	{
		cout << x << " ";
	}
	return 0;
}