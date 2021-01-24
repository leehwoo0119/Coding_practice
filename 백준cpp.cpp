#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;


void star(int n,int i,int j)
{
	
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
		cout << ' ';
		return;		
	}
	else
	{
		if (n / 3 == 0)
		{
			cout << '*';
			return;
		}
			
		else
			star(n / 3, i, j);
	}
}

int main()
{
	int N = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			star(N, i, j);
		}
		cout << endl;
	}

	return 0;
}