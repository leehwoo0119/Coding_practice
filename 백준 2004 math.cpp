#include <iostream>
#include <algorithm>
using namespace std;


long long cal(long long n, int type)
{
	long long sum = 0;
	//���μ� �����ϸ� 5�� ������ ���� �Ŷ�� �����ؼ� ����Ʋ�ȴ�.
	while (n >= type)
	{		
		sum += n / type;
		n /= type;
	}	
	
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long N = 0, M = 0;

	cin >> N >> M;

	//���丮���� �� ������� �ᱹ ���ڸ� 0�� ������ ���ϸ�
	//������ �и�� ������ 0�� ������ �Ű澲��ȴ�
	long long Fivesum = (long long)(cal(N, 5) - (cal(M, 5) + cal(N - M, 5)));
	long long Twosum = (long long)(cal(N, 2) - (cal(M, 2) + cal(N - M, 2)));
	cout << min(Fivesum, Twosum);
	return 0;
}

