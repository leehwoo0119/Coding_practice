#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[1500002] = { 0, };
int main()
{	
	int n = 0;
	cin >> n;
	//시간,금액
	vector<pair<int, int>>v;
	
	int t = 0, p = 0;
	v.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> t >> p;
		v.push_back(make_pair(t,p));
	}
	v.push_back(make_pair(0, 0));
	int currentMax = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		currentMax = max(currentMax, dp[i]);
		if (v[i].first + i <= n + 1)
		{
			dp[v[i].first + i] = max(currentMax + v[i].second, dp[v[i].first + i]);
		}
	}


	cout << currentMax;
	return 0;
}