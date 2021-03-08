#include <iostream>
#include <cmath>
//#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N1= 0, N2 = 0;

	cin >> N1 >> N2;
	
	int cnt = 0;
	for (int i = N1; i <= N2; i++)
	{
		if (i == 2 || i == 3)
		{
			cout << i << '\n';
			continue;
		}
		//소수는 제곱근 전까지만 구해도 판별가능
		int num = sqrt(i);
		for (int j = 2; j <= num; j++)
		{
			if (i % j == 0)
				break;
			if (j == num)cout << i << '\n';
		}
	}
	return 0;
}