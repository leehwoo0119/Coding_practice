#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;

	cin >> N;

	/*N / 5 = 5 , 10 �϶� 0���� N / 25 , 
	25�϶� 0���� N / 125 , 125�϶� 0����(500������ 625�� �ʿ����)*/
	cout << N / 5 + N / 25 + N / 125;
}
