#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int gcd(int a, int b)
{
	int c = 0;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int icm(int a, int b)
{
	return a * b / gcd(a, b);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a = 0, b = 0;
	cin >> a >> b;
	//유클리드 호제법 사용하기위해 swap
	if (a > b)swap(a, b);
	cout << gcd(a, b) << '\n';
	cout << icm(a, b);
	return 0;
}