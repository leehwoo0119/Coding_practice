#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	vector<char>v; 
	vector<char>vSave;
	int alpha[26] = {0,};
	cin >> s;

	sort(s.begin(), s.end());
	for (char x : s)
	{
		alpha[x - 'A']++;
	}
	//Ȧ���� �Ǵ� ����
	int cnt = 0;
	bool isReverse = true;
	char middle;
	for (int i = 0; i < 26; i++)
	{
		//���� ���� ��ŭ ����
		for (int j = 0; j < alpha[i] / 2; j++)
			v.push_back(i + 'A');
		//���� ���ĺ� ������ Ȧ���ϰ��
		if (alpha[i] % 2 != 0) 
		{
			cnt++; 	
			//�ϳ��� ����� ���� == ������ ��������
			if (cnt == 1)middle = i + 'A';		
		}	
		//�� �̻��̸� ���� �� ����
		if (cnt >= 2) {
			cout << "I'm Sorry Hansoo\n";
			isReverse = false;
			break;
		}
	}
	if (isReverse)
	{
		vSave = v;
		reverse(v.begin(), v.end());
		//���ĺ� ���� Ȧ���ΰ��� �����Ҷ�
		if (cnt == 1)					
			vSave.push_back(middle);
		
		for (int i = 0; i < v.size(); i++)
			vSave.push_back(v[i]);		
	}
	for (auto x : vSave)
		cout << x;
	return 0;
}

