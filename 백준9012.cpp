#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	vector<string>v;
	vector<int>Cnt;
	string value;
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		v.push_back(value);
	}
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int t = 0; t < v[i].length(); t++)
		{
			if (v[i][t] == '(')cnt++;
			else if (v[i][t] == ')')cnt--;
			if (cnt < 0)break;
		}
		if (cnt == 0)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}