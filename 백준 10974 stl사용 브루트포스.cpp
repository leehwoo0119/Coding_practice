#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)

{
	int n = 0;
	vector<int>v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		v.push_back(i + 1);
	}

	do {
		for (auto it = v.begin(); it != v.end(); it++)
		{
			cout << *it << ' ';
		}
		cout << endl;
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}



