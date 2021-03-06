#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string>v;

	string s;
	cin >> s;
	v.push_back(s);
	while(1)
	{
		s.erase(s.begin());
		if (s.empty())break;
		v.push_back(s);
	}

	sort(v.begin(), v.end());

	for (string x : v)
	{
		cout << x << '\n';
	}
	return 0;
}