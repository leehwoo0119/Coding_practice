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

	//set�� insert�� �ڵ����ĵǰ� �ߺ��� key���� insert�����ʴ´�.
	set<int>s;

	int value = 0;;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		s.insert(value);
	}

	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << " " << '\n';
	}

	return 0;
}