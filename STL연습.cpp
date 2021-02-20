#include <iostream>
#include <map>
using namespace std;


int main()
{
	map<int, int>d1;
	map<int, int>d2;

	
	for (int i = 1; i <= 9; i += 2)
	{
		d1[i] = i * i;
		d2[i] = i * i;
	}
	cout << d1.size() << endl;
	cout << d2.size() << endl;
	for (int i = 1; i <= 10; i++)
	{
		if (d1[i])cout << i << ',';
	}
	cout << endl;
	for (int i = 1; i <= 10; i++)
	{
		if(d2.count(i))cout << i << ',';
	}
	cout << endl;
	cout << d1.size() << endl;
	cout << d2.size() << endl;
	return 0;
}