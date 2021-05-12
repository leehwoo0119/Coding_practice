#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	int n = 0;
	cin >> n;

	vector<int>input;

	for (int i = 1; i <= n; i++)
	{
		int insert = 0;
		cin >> insert;
		input.push_back(insert);
	}

	if (next_permutation(input.begin(), input.end()))
	{
		for (auto it = input.begin(); it != input.end(); it++)
		{
			cout << *it << ' ';
		}
	}
	else cout << "-1";
	
	
	

	return 0;
}