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
	//�ߺ��� key���� insert�ϱ����� ��Ƽ�� ���
	//��Ƽ���� ��� ���ڸ� key����, �� �ڵ����� �����Ͽ� ������
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