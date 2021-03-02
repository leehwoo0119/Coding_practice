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
			//(의시작은 막대기 시작or 레이저시작 == st의 크기는 막대기의 크기
			st.push(value[i]);
		}
		else
		{
			//막대기가 끝나든 레이져가 끝나든 pop
			st.pop();
			//이경우는 레이져이므로 막대기수만큼 cnt++
			if (value[i - 1] == '(')
				cnt += st.size();
			//막대기 끝인경우는 cnt++
			else
				cnt++;
		}
	}
	cout << cnt;
	return 0;
}