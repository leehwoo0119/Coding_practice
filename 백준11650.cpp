#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int N = 0;
	//중복된 key값을 insert하기위해 멀티맵 사용
	multiset<pair<int, int>>m;

	int x = 0,  y = 0; 

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		m.insert(make_pair(x,y));
	}
	//sort(m.begin(), m.end());
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->first << " " << iter->second << '\n';
	}
	
	return 0;
}