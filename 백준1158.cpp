#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0 , K = 0;
	queue<int>q;
	cin >> N;
	cin >> K;

	for (int i = 1; i <= N; i++)
		q.push(i);
	
	int back = 0;
	cout << "<";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K - 1; j++)
		{
			back = q.front();
			q.pop();
			q.push(back);
		}	
		cout << q.front();
		if (i != N - 1) cout << ", ";
		q.pop();

	}
	cout << ">";
	return 0;
}
