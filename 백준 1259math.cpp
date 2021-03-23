#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	string saveN;
	do
	{
		cin >> N;
		saveN = N;
		reverse(saveN.begin(), saveN.end());
		if (N != "0")
		{
			if (saveN == N)cout << "yes" << endl;
			else cout << "no" << endl;
		}
		
	} while (N != "0");
	
	return 0;
}

