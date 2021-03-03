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
	vector<int>v(N);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		v.push_back(i);

	int v1 = 0, v2 = 0, v3 = 0;
	auto it = v.begin();
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2 >> v3;
		//it + v3 - 1�� �Ǿ����εΰ� it + v1 - 1���� it + v2 - 1���� ȸ����Ŵ
		rotate(it + v1 - 1, it + v3 - 1, it + v2);
		cout << endl;
	}


	for (int x : v)
		cout << x << " ";
	return 0;
}