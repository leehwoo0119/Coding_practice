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
		//arr���� 1�̸� �н�
		for (int j = 2; j < arr[i]; j++)
		{
			
			//�Ҽ��� �ƴϸ�(1�̿��� �ٸ����� ������������)break
			if (arr[i] % j == 0)
				break;
			//�Է°� - 1 ���� �׷��� �ʴٸ� cnt++
			if (j == arr[i] - 1)cnt++;
		}		
	}

	cout << cnt;
	delete[]arr;
	return 0;
}