#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N = 0;	
	cin >> N;
	string arr;
	vector<pair<int, string>>p1;

	for (int i = 0; i < N; i++)
	{
		cin >> arr;
		p1.push_back({ arr.size(),arr });
	}
	sort(p1.begin(), p1.end());
	auto it = unique(p1.begin(), p1.end());
	p1.resize(it - p1.begin());
	cout<<"----------------------------------"<<endl;
	cout << p1.size();
	for (auto x : p1)
	{
		cout << x.second << endl;
	}
	return 0;
}