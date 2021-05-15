#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int insert[11][11] = { 0, };
int visitedLogic[11] = { 0, };

int main(void)
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		visitedLogic[i] = i;
		for (int j = 0; j < n; j++)
		{
			int input = 0;
			cin >> input;
			insert[i][j] = input;
		}
	}
	int minTemp = INT_MAX;
	do {
		int temp = 0;
		bool isFlag = false;
		for (int i = 0; i < n; i++)
		{
			if (insert[visitedLogic[i]][visitedLogic[i + 1]] == 0)
			{
				isFlag = true;
				break;
			}
			else
				temp += insert[visitedLogic[i]][visitedLogic[i + 1]];
			//cout << visitedLogic[i] << ' ';
		}
		if (!isFlag && insert[visitedLogic[n - 1]][visitedLogic[0]] != 0)
			temp += insert[visitedLogic[n - 1]][visitedLogic[0]];
		minTemp = min(minTemp, temp);
		//cout << temp;
		//cout << '\n';
	} while (next_permutation(visitedLogic, visitedLogic + n));
	cout << minTemp;
	return 0;
}



