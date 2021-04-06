#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	int arr[1002] = { 0, };
	int dp[3]={0,1,2};
	cin >> n;
	
	int input = 0;
	int start = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		if (start == 0 && input == 0)start = i;
		arr[i] = input;
	}
	int cnt = 0;
	int s = 0;
	for (int i = start; i <= n; i++)
	{
		if (arr[i] == dp[s])
		{
			cnt++; s++;
		}
		if (s == 3)s = 0;
	}
	cout << cnt;
	return 0;
}