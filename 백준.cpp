#include <iostream>
#include <list>

using namespace std;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N = 0;
	
	string str;

	cin >> str;
	cin >> N;
	list<char> l(str.begin(), str.end());
	auto iter = l.end();
	for (int i = 0; i < N; i++)
	{
		char s;
		
		cin >> s;		
			switch (s)
			{
			case 'L':
				if (iter != l.begin()) iter--;
				break;
			case 'D':
				if (iter != l.end()) iter++;
				break;
			case 'B':
				if (iter != l.begin()) iter = l.erase(--iter);
				break;
			default:
				char x;
				cin >> x;
				iter = l.insert(iter, x);
				iter++;
				break;			
			}
	
	}
	for (auto& x : l)
	{
		cout << x;
	}
	
	return 0;
}