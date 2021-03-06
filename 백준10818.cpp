#include <iostream>
#include <vector>
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
	int value = 0;
	for (int i = 0; i < N; i++)
		cin >> arr[i];


	sort(arr + 0, arr + N);
	cout << arr[0] << " " << arr[N - 1];
	delete[]arr;
	return 0;
}