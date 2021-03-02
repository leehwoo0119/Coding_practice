#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char>st;
	string value;
	cin >> value;

	int cnt = 0;
	for (int i = 0; i < value.length(); i++)
	{
		if (value[i] == '(')
		{
			//(�ǽ����� ����� ����or ���������� == st�� ũ��� ������� ũ��
			st.push(value[i]);
		}
		else
		{
			//����Ⱑ ������ �������� ������ pop
			st.pop();
			//�̰��� �������̹Ƿ� ��������ŭ cnt++
			if (value[i - 1] == '(')
				cnt += st.size();
			//����� ���ΰ��� cnt++
			else
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}