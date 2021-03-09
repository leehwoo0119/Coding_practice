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
	//8�� 2�� 3���̹Ƿ� 3�ڸ��� ��� ����ϸ� 10������ ��ȯ�� �ʿ䰡 ����
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