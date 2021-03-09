#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	vector<char>v;
	stack<int>st;
	cin >> s;	

	for (int i = 0; i < s.length(); i++)
		v.push_back(s[i]);
	int tmp = 0;
	//8은 2의 3승이므로 3자리씩 끊어서 계산하면 10진수로 변환할 필요가 없음
	for (int i = s.length() - 3; i >= -2; i-=3)
	{
		if (i == -2)
			tmp = (s[i + 2] - '0');
		else if (i == -1)
			tmp = (2 * (s[i + 1] - '0')) + (s[i + 2] - '0');
		else
			tmp = (4 * (s[i] - '0')) + (2 * (s[i + 1] - '0')) + (s[i + 2] - '0');
		st.push(tmp);
	}

	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
	return 0;
}