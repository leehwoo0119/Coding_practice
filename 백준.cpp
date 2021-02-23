#include <iostream>
#include <list>

using namespace std;
char s[1000001];
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int N = 0;


	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		list<char> l;
		auto iter = l.begin();
		for (int j = 0; s[j] != 0; j++)
		{
			switch (s[j])
			{
			case '<':
				if (iter != l.begin()) iter--;
				break;
			case '>':
				if (iter != l.end()) iter++;
				break;
			case '-':
				if (iter != l.begin()) iter = l.erase(--iter);
				break;
			default:
				iter = l.insert(iter, s[j]);
				iter++;
				break;
			}
		}
		for (auto x = l.begin(); x != l.end(); x++)
		{
			cout << *x;
		}
		cout << '\n';
	}


	return 0;
}