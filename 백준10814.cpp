#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int N = 0;
	//�ߺ��� key���� insert�ϱ����� ��Ƽ�� ���
	multimap<int, string>m;

	int age = 0; 
	string name;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		m.insert(make_pair(age,name));
	}
		
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->first << " " << iter->second << '\n';
	}
	
	return 0;
}