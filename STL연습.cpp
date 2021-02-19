#include <iostream>
#include <vector>
using namespace std;

void func(vector<int> a)
{
	for (vector<int>::iterator it = a.begin();
		it != a.end();
		++it)
	{
		cout << *it << ' ';
	}
	cout << endl;
}
int main()
{
	vector<int>a = { 1,2,3 };

	auto it = a.begin();
	a.insert(it, 4);

	func(a);

	it = a.begin() + 1;
	a.insert(it, 5 , 0);

	func(a);
	
	it = a.begin() + 2;
	vector<int> b = { 10,20 };
	a.insert(it, b.begin(), b.end());

	func(a);

	vector<int>c = { 1,2,3,4,5 };
	c.erase(c.begin() + 1, c.begin() + 3);

	func(c);
	return 0;
}