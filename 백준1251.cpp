#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	string s;
	cin >> s;
	
	
	string a, b, c, answer = "";
	for (int i = 1; i < s.length() - 1; ++i)
	{
		for (int j = 1; j < s.length() - i; ++j)
		{
			a = s.substr(0, i);
			b = s.substr(i, j);
			c = s.substr(i + j);
			reverse(a.begin(), a.end());
			reverse(b.begin(), b.end());
			reverse(c.begin(), c.end());
			if (answer == "")
			{
				answer = a + b + c;
			}
			else if (a + b + c < answer)
			{
				answer = a + b + c;
			}
		}
	}
	cout << answer;
	return 0;
}
