#include <iostream>
#include <cmath>
//#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int* arr = 0;

	cin >> N;
	arr = (int*)new int[N];
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 2 || arr[i] == 3)
		{
			cnt++;
			continue;
		}
		//소수는 제곱근 전까지만 구해도 판별가능
		int num = sqrt(arr[i]);
		for (int j = 2; j <= num; j++)
		{
			if (arr[i] % j == 0)
				break;
			if (j == num)cnt++;
		}
	}
	cout << cnt;
	delete[]arr;
	return 0;
}