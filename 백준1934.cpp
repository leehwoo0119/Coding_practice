#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int gcd(int a, int b)
{
	int c = 0;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int icm(int a, int b)
{
	return a * b / gcd(a, b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;

	cin >> N;

	vector<pair<int, int>>v;

	for (int i = 0; i < N; i++)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		if (a > b)swap(a, b);
		v.push_back(make_pair(a, b));
	}
	
	for (int i = 0; i < N; i++)
		cout << icm(v[i].first, v[i].second) << '\n';
	return 0;
}