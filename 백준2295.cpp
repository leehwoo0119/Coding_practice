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
	v.push_back(0);
	int n = 0;

	cin >> n;
	int value = 0;
	
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		v.push_back(value);
	}
	
	sort(v.begin(), v.end());

	vector<int>save;
	save.push_back(0);
	for (auto i = v.begin(); i != v.end(); i++)
	{
		for (auto j = i; j != v.end(); j++)
			save.push_back(*i + *j);
	}
	sort(save.begin(), save.end());
	
	/*for (auto i : save)
	{
		cout << i << " ";
	}*/
	bool flag = false;
	for (auto i = v.end() - 1; i != v.begin(); i--)
	{
		for (auto j = i; j != v.begin(); j--)
		{

			if (binary_search(save.begin(), save.end(), *i - *j))
			{
				cout << *i;
				flag = true;
			}
			if (flag)break;
		}
		if (flag)break;
	}
	return 0;
}
