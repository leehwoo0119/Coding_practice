#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S = 0;
int arr[21];
int answer = 0;
vector<int>v;

void Solve(int _cnt, int _stage)
{
	if (v.size() == _stage)
	{
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}
		if (sum == S)answer++;
		return;
	}
	for (int i = _cnt; i < N; i++)
	{
		v.push_back(arr[i]);
		Solve(i + 1, _stage);
		v.pop_back();
	}
}

int main() 
{
	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++)
	{
		Solve(0, i);
	}	
	cout << answer;
}