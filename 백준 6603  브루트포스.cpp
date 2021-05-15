#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(void)

{

	while (1)
	{
		vector<int>v;
		vector<int>lottoLogic;

		int n = 0;

		cin >> n;

		if (n == 0)break;
		for (int i = 0; i < n; i++)
		{
			int input = 0;
			cin >> input;
			v.push_back(input);
			if (i < 6)lottoLogic.push_back(1);
			else lottoLogic.push_back(0);
		}

		do {
			for (int i = 0; i < n; i++)
			{
				if (lottoLogic[i] == 1)
				cout << v[i] << ' ';
			}
			cout << '\n';
		} while (prev_permutation(lottoLogic.begin(), lottoLogic.end()));
		cout << '\n';
	}
	
	return 0;
}



