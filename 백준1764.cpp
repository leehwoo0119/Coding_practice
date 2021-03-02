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

	vector<string>v1, v2;
	cin >> N;
	cin >> M;
	string value;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		v1.push_back(value);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> value;
		v2.push_back(value);
	}

	sort(v1.begin(), v1.end());

	int cnt = 0; int t = 0;
	vector<string>save;

	for (string i : v2)
	{
		if (binary_search(v1.begin(), v1.end(), i))
		{
			cnt++;
			save.push_back(i);
		}

		t++;
	}
	sort(save.begin(), save.end());
	cout << cnt << endl;
	for (string i : save)
	{
		cout << i << endl;
	}
	return 0;
}