#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void InputValue(int n, vector<int> &v)
{
	int value = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}

	sort(v.begin(), v.end());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N1 = 0, N2 = 0;
	vector<int>v1,v2;

	cin >> N1; cin >> N2;

	InputValue(N1, v1);
	InputValue(N2, v2);

	int cntA_B = 0; int cntB_A = 0;
	for (int x : v1)
		if (binary_search(v2.begin(), v2.end(), x))cntA_B++;

	for (int x : v2)
		if (binary_search(v1.begin(), v1.end(), x))cntB_A++;

	cntA_B = v1.size() - cntA_B;
	cntB_A = v2.size() - cntB_A;
	cout << cntA_B + cntB_A;
	return 0;
}
