#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	cin >> N;
	int value = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> value;
		if (value == 0)
		{
			if (pq.empty())cout << "- " << "0" << endl;
			else
			{

				cout << "- "<<pq.top() << endl;
				pq.pop();
			}
		}
		else
		{
			pq.push(value);
		}
	}
	
	return 0;
}