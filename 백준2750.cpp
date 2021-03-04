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
	//중복된 key값을 insert하기위해 멀티셋 사용
	//멀티셋은 모든 인자를 key저장, 즉 자동으로 정렬하여 저장함
	set<int>s;

	int value = 0;;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> value ;
		s.insert(value);
	}
	
	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << " " << '\n';
	}
	
	return 0;
}