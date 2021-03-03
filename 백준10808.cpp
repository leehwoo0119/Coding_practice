#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string value;
	//°ª push
	cin >> value;

	for (int i = 'a'; i != 'z' + 1; i++)
	{
		cout << count(value.begin(), value.end(), i) << " ";
	}
	
	return 0;
}