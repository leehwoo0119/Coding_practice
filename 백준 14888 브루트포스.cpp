#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(void)

{
	int n = 0;
	vector<int>v;
	int OperatorNum[4] = { 0, };
	vector<pair<int,int>>Operator;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input = 0;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 0; i < 4; i++)
	{
		int input = 0;
		cin >> input;
		OperatorNum[i] = input;
	}
	int t = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < OperatorNum[i]; j++)
		{
			Operator.push_back(make_pair(i,t++));
		}
	}
	int maxTemp = -1000000001, minTemp = 1000000001;
	do {
		int t = 0;
		int temp = v[t];		
		for (int i = 0; i < n - 1; i++, t++)
		{
			if (Operator[i].first == 0)
				temp +=  v[t + 1];
			if (Operator[i].first == 1)
				temp -=  v[t + 1];
			if (Operator[i].first == 2)
				temp *=  v[t + 1];
			if (Operator[i].first == 3)
				temp /=  v[t + 1];
			//cout << Operator[i].first << ' ';
			
		}
		maxTemp = max(maxTemp, temp);
		minTemp = min(minTemp, temp);
		//cout << temp << '\n';
		//cout << '\n';
	} while (next_permutation(Operator.begin(), Operator.end()));
	cout << maxTemp << '\n' << minTemp;
	return 0;
}



