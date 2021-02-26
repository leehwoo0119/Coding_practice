#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	bitset<100000>b1;
	bitset<100000>b2;
	cin >> b1;
	cin >> b2;

	cout << (b1 & b2) << endl;
	cout << (b1 | b2) << endl;
	cout << (b1 ^ b2) << endl;
	cout << (~b1) << endl;
	cout << (~b2) << endl;
	return 0;
}