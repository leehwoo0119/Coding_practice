#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath> //pow
typedef long long ll;
using namespace std;
vector<ll>v;
stack<ll>s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll A = 0, B = 0;
	ll N = 0;
	ll input = 0;
	
	cin >> A >> B >> N;
	while (N--)
	{
		cin >> input;
		v.push_back(input);
	}
	//A->10진수로 변환
	int tenSum = 0;
	for (int i = 0; i < v.size(); i++)
		tenSum += v[i] * pow(A, v.size() - 1 - i);
	//10->B진수로 전환
	int sumB = 0;
	while (tenSum / B != 0)
	{
		ll n = tenSum / B;
		s.push(tenSum % B);
		tenSum = n;
		if(tenSum / B == 0)s.push(n);
	}
	ll len = s.size();
	for (int i = 0; i < len; i++)
	{		
		cout << s.top();
		if (i != len - 1) cout << " ";
		s.pop();
	}
		
	return 0;
}

