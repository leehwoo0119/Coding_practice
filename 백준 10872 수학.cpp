#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;
	int sum = 1;

	cin >> N;
	while (N != 1)
	{
		if (N == 0)break;
		sum *= N;
		N--;
	}
		
	cout << sum;
}
