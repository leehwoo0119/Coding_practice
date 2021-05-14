#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)

{
	int E = 0, S = 0, M = 0;

	cin >> E >> S >> M;

	int i = 1, j = 1, k = 1;
	int cnt = 0;
	while (1)
	{
		cnt++;
		if (i == E && j == S && k == M)break;	
		i++; j++; k++;
		if (i == 16)i = 1;
		if (j == 29)j = 1;
		if (k == 20)k = 1;
	}
	cout << cnt;
	return 0;
}



