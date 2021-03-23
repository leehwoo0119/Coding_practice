#include <iostream>
#include <algorithm>
using namespace std;


long long cal(long long n, int type)
{
	long long sum = 0;
	//소인수 분해하면 5가 무조건 작을 거라고 생각해서 많이틀렸다.
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

	//팩토리얼은 별 상관없다 결국 뒷자리 0의 갯수만 구하면
	//됨으로 분모와 분자의 0의 갯수만 신경쓰면된다
	long long Fivesum = (long long)(cal(N, 5) - (cal(M, 5) + cal(N - M, 5)));
	long long Twosum = (long long)(cal(N, 2) - (cal(M, 2) + cal(N - M, 2)));
	cout << min(Fivesum, Twosum);
	return 0;
}

