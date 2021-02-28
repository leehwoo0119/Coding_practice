#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, pair<int, int>>m;

	m["black"] = make_pair(0, 1);
	m["brown"] = make_pair(1, 10);
	m["red"] = make_pair(2, 100);
	m["orange"] = make_pair(3, 1000);
	m["yellow"] = make_pair(4, 10000);
	m["green"] = make_pair(5, 100000);
	m["blue"] = make_pair(6, 1000000);
	m["violet"] = make_pair(7, 10000000);
	m["grey"] = make_pair(8, 100000000);
	m["white"] = make_pair(9, 1000000000);

	string first, second, third;
	cin >> first;
	cin >> second;
	cin >> third;

	map<string, pair<int, int>>::iterator iter;


	cout << (long long)((m[first].first) * 10 + (m[second].first))* m[third].second;

	return 0;
}
