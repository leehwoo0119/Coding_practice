#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	int i = 0;
	int arr[302];
	int dp[302];

	cin >> n;
	int input = 0;
	for (i = 1; i <= n; i++)
	{
		cin >> input;
		arr[i] = input;
	}
	dp[1] = arr[1];
	dp[2] = max(arr[2], arr[1] + arr[2]);
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	
	for (i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	}
	cout << dp[n];
	return 0;
}