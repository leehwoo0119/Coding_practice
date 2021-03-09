#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int>st;
	int n = 0;
	cin >> n;
	if (n == 0)cout << 0;
	else
	{
		while (n != 0)
		{
			int val = 1;
			if (n % -2 < 0)val = -1;
			st.push(val * (n % -2));


			if (n % -2 == 0)
				n /= -2;
			else
				n = (n - 1) / -2;
		}
		while (!st.empty())
		{
			cout << st.top();
			st.pop();
		}
	}
	
	
	return 0;
}