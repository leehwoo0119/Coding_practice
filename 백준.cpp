#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N = 0;
	int s = 0;
	vector<pair<int, int>> v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		v.push_back({ i + 1, s });
		
	}
	int move = 0;
	while (1)
	{
		
		cout << v.front().first << " ";
		move = v.front().second;
		v.erase(v.begin());
		if (v.empty())break;
		if (move > 0)
		{
			for (int i = 0; i < move - 1; i++)
			{
				v.push_back(v.front());
				v.erase(v.begin());
			}
		}
		else
		{
			for (int i = 0; i < -move; i++)
			{
				v.insert(v.begin(),v.back());
				v.pop_back();
			}
		}
	}

	return 0;
}