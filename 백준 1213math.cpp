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
	//홀수가 되는 갯수
	int cnt = 0;
	bool isReverse = true;
	char middle;
	for (int i = 0; i < 26; i++)
	{
		//앞의 절반 만큼 저장
		for (int j = 0; j < alpha[i] / 2; j++)
			v.push_back(i + 'A');
		//같은 알파벳 갯수가 홀수일경우
		if (alpha[i] % 2 != 0) 
		{
			cnt++; 	
			//하나면 만들기 가능 == 가운대로 보내버림
			if (cnt == 1)middle = i + 'A';		
		}	
		//그 이상이면 만들 수 없음
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
		//알파벳 수가 홀수인것이 존재할때
		if (cnt == 1)					
			vSave.push_back(middle);
		
		for (int i = 0; i < v.size(); i++)
			vSave.push_back(v[i]);		
	}
	for (auto x : vSave)
		cout << x;
	return 0;
}

