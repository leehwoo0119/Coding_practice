#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int gcd(int a, int b)
{
	int c = 0;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
long long cal(int* arr, int n)
{
	long long tmp = 0;
	//가능한 모든쌍 계산
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			tmp += gcd(arr[i], arr[j]);		
	}
	return tmp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N1 = 0, N2 = 0;

	cin >> N1;

	int** arr = 0;
	
	arr = (int**)new int*[N1];

	
	for (int i = 0; i < N1; i++)
	{
		cin >> N2;
		arr[i] = (int*)new int[N2];
		for (int j = 0; j < N2; j++)
		{			
			int a = 0;
			cin >> a;
			arr[i][j] = a;
		}
		//유클리드 호제법 사용하기 위해 sort
		sort(*(arr+i) + 0, *(arr + i) + N2);
		cout << cal(arr[i], N2);
		if (i != N1 - 1)cout << "\n";
	}

	for (int i = 0; i < N1; i++)
		delete[]arr[i];
	delete[]arr;
	
	
	return 0;
}