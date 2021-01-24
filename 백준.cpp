#include<stdio.h>
#include<math.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

void Input(char** star, int n, int w, int h, int dir)
{
	int height = ((int)pow(2, n) - 1);
	//시작지점
	star[h][w] = '*';
	if (n == 1)
		return;

	int left = w; int right = w;

	for (int i = 0; i < height - 1; i++)
	{
		if (dir == 1)
			h--;
		else
			h++;

		left--; right++;
		star[h][left] = '*'; star[h][right] = '*';
	}

	for (int i = left + 1; i < right; i++)
	{
		star[h][i] = '*';
	}
	if (dir == 1)
	{
		h++;
		dir = 0;
	}
	else if (dir == 0)
	{
		h--;
		dir = 1;
	}

	Input(star, n - 1, w, h, dir);
}
int main()
{
	char** star = 0;
	int N = 0;


	scanf("%d", &N);

	int height = ((int)pow(2, N) - 1);
	int weight = (height * 2 - 1);

	//0=홀수 1=짝수
	int dir = 0;

	if (N % 2 == 0)
		dir = 1;
	else
		dir = 0;

	if (star == NULL)
	{
		star = (char**)malloc(height * sizeof(char*));

		for (int i = 0; i < height; i++)
		{
			//우측 공백부분 메모리 삭제
			//짝수시 메모리 할당
			if (dir == 1)
			{
				star[i] = (char*)malloc((weight - i) * sizeof(char));
			}
			//홀수시 메모리 할당
			if (dir == 0)
			{
				star[i] = (char*)malloc((height + i) * sizeof(char));
			}
		}
	}
	for (int i = 0; i < height; i++)
	{
		if (dir == 1)
		{
			for (int j = 0; j < (weight - i); j++)
			{
				star[i][j] = ' ';
			}
		}
		if (dir == 0)
		{
			for (int j = 0; j < (height + i); j++)
			{
				star[i][j] = ' ';
			}
		}
	}

	int start_h = 0;

	if (dir == 1)
		start_h = height - 1;

	int start_w = height - 1;

	Input(star, N, start_w, start_h, dir);

	for (int i = 0; i < height; i++)
	{
		if (dir == 1)
		{
			for (int j = 0; j < (weight - i); j++)
			{
				printf("%c", star[i][j]);
			}
		}
		if (dir == 0)
		{
			for (int j = 0; j < (height + i); j++)
			{
				printf("%c", star[i][j]);
			}
		}
		printf("\n");
	}

	if (star != NULL)
	{
		for (int i = 0; i < height; i++)
		{
			free(star[i]);
		}
		free(star);
	}
}