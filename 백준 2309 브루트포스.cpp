#include<iostream>
#include <algorithm>
using namespace std;

int main() {

	int arr[9] = { 0, };
	int Totaltemp = 0;

	for (int i = 0; i < 9; i++)
	{
		int input = 0;
		cin >> input;
		arr[i] = input;
		Totaltemp += input;
	}
	int Answertemp = Totaltemp - 100;

	bool flag = false;
	for (int left = 0; left < 8; left++)
	{
		for (int right = left + 1; right < 9; right++)
		{
			if (arr[left] + arr[right] == Answertemp)
			{
				arr[left] = -1;
				arr[right] = -1;
				flag = true;
			}
			if (flag)break;
		}	
		if (flag)break;
	}

	sort(arr, arr + 9);

	for (int i = 2; i < 9; i++)
	{
		cout << arr[i] <<'\n';
	}

	return 0;
}