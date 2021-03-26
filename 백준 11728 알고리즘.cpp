#include <iostream>
#include <algorithm>
#include <set>

typedef long long ll;
using namespace std;
multiset<ll>s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0;
	ll input = 0;
	cin >> N >> M;
	int cnt = N + M;
	while (cnt--)
	{
		cin >> input;
		s.insert(input);
	}
	for (auto it = s.begin(); it != s.end(); it++)
	{
		cout << *it;
		if (it != prev(s.end()))cout << " ";
	}
	return 0;
}