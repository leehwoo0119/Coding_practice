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

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	int sum = 0, max = 0;
	do {
		sum = 0;
		for (int i = 0; i < N - 1; i++)
		{
			int plusminus = 1;
				if (arr[i] - arr[i + 1] < 0)plusminus = -1;

				sum += plusminus * (arr[i] - arr[i + 1]);
				//cout << sum << " ";
		}
		if (max < sum)
			max = sum;	
	} while (next_permutation(arr, arr + N));
	
	cout << max;
	delete[]arr;
	return 0;
}