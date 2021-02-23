#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N = 0;
	int s1 = 0, s2 = 0;
	pair<int, int>p1;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s1;
		cin >> s2;
		p1 = make_pair(s1, s2);
		cout << p1.first + p1.second << '\n';
	}

	return 0;
}