#include <iostream>
#include <string>
#include <cmath>
#include <stack>
//#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N = 0;
	int B = 0;
	cin >> N >> B;
	long long tmp = 0;

	int cal = 0;
	stack<int> s1;
	stack<int> s;
	while (N != 0)
	{
		if (N % B >= 0 && N % B <= 9)
		{
			cal = (N % B);
			s.push(cal);
		}
			
		else
		{
			cal = (N % B) + 55;
			s.push((char)cal);
		}			
		N /= B;	
	}
	while (!s.empty())
	{
		if (s.top() < 10)
			cout << s.top();
		else
			cout << (char)s.top();
		s.pop();
	}
	return 0;
}