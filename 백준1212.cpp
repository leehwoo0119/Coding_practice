#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case '0':
			if (i == 0)cout << "0";
			else cout << "000";
			break;
		case '1':
			if (i == 0)cout << "1";
			else cout << "001";
			break;
		case '2':
			if (i == 0)cout << "10";
			else cout << "010";
			break;
		case '3':
			if (i == 0)cout << "11";
			else cout << "011";
			break;
		case '4':
			cout << "100";
			break;
		case '5':
			cout << "101";
			break;
		case '6':
			cout << "110";
			break;
		case '7':
			cout << "111";
			break;
		}		
	}
	return 0;
}