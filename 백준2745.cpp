#include <iostream>
#include <string>
#include <cmath>
//#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	int B = 0;
	cin >> N >> B;
	long long tmp = 0;
	//������ ���
	int powCnt = N.length() - 1;
	int cal = 0;
	for (int i = 0; i < N.length(); i++, powCnt--)
	{
		if(N[i] >= '0' && N[i] <= '9')
			cal = N[i] - '0';
		//���ĺ��ϰ�� ���
		else 
			cal = N[i] - 55;
		tmp += cal * pow(B, powCnt);
	}
	cout << tmp;

	return 0;
}