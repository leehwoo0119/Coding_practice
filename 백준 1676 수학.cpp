#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;

	cin >> N;

	/*N / 5 = 5 , 10 일때 0증가 N / 25 , 
	25일때 0증가 N / 125 , 125일때 0증가(500까지라 625는 필요없음)*/
	cout << N / 5 + N / 25 + N / 125;
}
