#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GCD(int a, int b) {
	//if (a < b)swap(a, b);
	while (1) {
		int r = a % b;
		if (r == 0) return b;

		a = b;
		b = r;
	}
}
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>>v;
	int n = 0, m = 0;
	int tmp = 0;
	cin >> n >> m;
	int gcd = 0;
	for (int i = n; i <= m; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (j == 1 || j == i - 1) gcd = 1;
			else gcd = GCD(i, j);
			v.push_back(make_pair((j/ gcd),(i / gcd)));
		}		
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());


	//for (auto x = s.begin(); x != s.end(); x++)cout << x->first << ", "<<x->second<<endl;
	cout << v.size() + 1;
	return 0;
}

