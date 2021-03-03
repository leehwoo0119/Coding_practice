#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int>v;

	int N = 0;
	int value = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		v.push_back(value);
	}
	int search_value = 0;
	cin >> search_value;
	vector<int>::iterator iter;


	cout << count(v.begin(), v.end(), search_value);
	return 0;
}