#include<iostream>
#include <algorithm>
using namespace std;

int cnt;

void cal(int temp,int n)
{
	//cout << temp << '\n';
	if (temp > n)return;

	if (temp == n) cnt++;
	cal(temp + 1, n);  
	cal(temp + 2, n);  
	cal(temp + 3, n);   
}
int main() {

	int T = 0;
	cin >> T;

	while (T--)
	{
		int n = 0;
		cin >> n;
		cnt = 0;
		int temp = 0;
		//2ÀÏ °æ¿ì temp 1->2->cnt++->3->return->2->4->return->2->5
		//->return->2->1->3->return->2->4...
		cal(0, n);
		cout << cnt << '\n';
	}
	
	

	return 0;
}