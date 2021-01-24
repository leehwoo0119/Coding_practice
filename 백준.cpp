#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void star(char** arr,int sizeX, int x, int y, int curveCnt,int curveDir)
{
	arr[y][x] = '*';

	for (int i = 0; i < curveCnt; i++)
	{		
		if (curveDir == 0)
		{
			y--;
		}		
		else if (curveDir == 1)
		{
			x++;
		}
		else if (curveDir == 2)
		{
			y++;
		}
		else if (curveDir == 3)
		{
			x--;
		}
		if (y == 0 && x == sizeX) return;
			arr[y][x] = '*';
	}
	
	if (curveDir == 1)
		curveCnt += 2;
	if (curveDir == 3)
	{		
		curveCnt += 2; curveDir = -1;
	}
		
	star(arr, sizeX, x, y, curveCnt, curveDir+1);
}
int main()
{
	int N = 0;
	char** arr = 0;

	cin >> N;

	int sizeY = 0, sizeX = 0;

	if (arr == NULL)
	{
		if (N == 1)
		{
			sizeY = 1; sizeX = 1;
		}
		else 
		{
			sizeY = (4 * N) - 1; sizeX = (4 * N) - 3;
		} 

		arr=(char**)new char* [sizeY];

		for (int i = 0; i < sizeY; i++)
		{
			if (i == 1)sizeX = 2;
			else if (i == sizeY - 1)sizeX = (4 * N) - 3;
			else sizeX = (4 * N) - 2;
			arr[i] = (char*) new int[sizeX];
			memset(arr[i], ' ', sizeof(char) * sizeX);
		}
	}

	int startX = sizeX / 2; int startY = sizeY / 2 + 1;
	int curveCnt = 2; int curveDir = 0;

	if(N==1)
		arr[0][0] = '*';
	else
		star(arr, sizeX, startX, startY, curveCnt, curveDir);
	
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			if (i == 1)sizeX = 2;
			else if (i == sizeY - 1)sizeX = (4 * N) - 3;
			else sizeX = (4 * N) - 2;
			cout << arr[i][j];
		}
		cout << endl;
	}
	if (arr != NULL)
	{
		for (int i = 0; i < sizeY; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	return 0;
}