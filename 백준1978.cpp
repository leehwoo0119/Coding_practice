#include <iostream>
#include <algorithm>

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
		if (arr[i] == 2)
		{
			cnt++;
			continue;
		}
		//arr값이 1이면 패스
		for (int j = 2; j < arr[i]; j++)
		{
			
			//소수가 아니면(1이외의 다른수와 나눠떨어지면)break
			if (arr[i] % j == 0)
				break;
			//입력값 - 1 까지 그렇지 않다면 cnt++
			if (j == arr[i] - 1)cnt++;
		}		
	}

	cout << cnt;
	delete[]arr;
	return 0;
}