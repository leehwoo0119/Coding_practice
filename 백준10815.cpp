#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void func(int n, vector<int>& v)
{
	int value = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>v1;
	vector<int>v2;

	int N1 = 0, N2 = 0;

	cin >> N1;
	func(N1, v1);
	cin >> N2;
	func(N2, v2);

	sort(v1.begin(), v1.end());

	for (int x : v2)
	{
		if (binary_search(v1.begin(), v1.end(), x)) cout << "1 ";
		else cout << "0 ";
	}

	return 0;
}
