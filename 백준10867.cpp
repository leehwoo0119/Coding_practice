#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	int N = 0;
	int value = 0;
	vector<int>v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	sort(v.begin(), v.end());
	auto it = unique(v.begin(), v.end());
	v.resize(it - v.begin());

	for (auto x : v)
	{
		cout << x << " ";
	}
	return 0;
}