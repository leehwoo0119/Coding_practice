#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long DP[91] = { 0, };
	int n = 0;

	cin >> n;
	DP[0] = 0;
	DP[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	cout << DP[n];
	return 0;
}