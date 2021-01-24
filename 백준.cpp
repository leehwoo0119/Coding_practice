#include<stdio.h>
#include<math.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

void Input(char** star, int n, int w, int h, int dir)
{
	int height = ((int)pow(2, n) - 1);
	//��������
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

	//0=Ȧ�� 1=¦��
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
			//���� ����κ� �޸� ����
			//¦���� �޸� �Ҵ�
			if (dir == 1)
			{
				star[i] = (char*)malloc((weight - i) * sizeof(char));
			}
			//Ȧ���� �޸� �Ҵ�
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