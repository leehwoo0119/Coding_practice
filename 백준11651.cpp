#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool func(pair<int, int> &a, pair<int, int>&b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N = 0;
	//중복된 key값을 insert하기위해 멀티셋 사용
	//멀티셋은 모든 인자를 key저장, 즉 자동으로 정렬하여 저장함
	vector<pair<int, int>>v;

	int x = 0, y = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(),func);
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		cout << iter->first << " " << iter->second << '\n';
	}

	return 0;
}