#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
	char s1[10001] = { 0, };
	char s2[10001] = { 0, };
	long long int answer = 0;
	scanf("%s %s", s1, s2);

	for (int i = 0; i < strlen(s1); i++)
	{
		for (int j = 0; j < strlen(s2); j++)
		{
			answer += (s1[i] - '0') * (s2[j] - '0');
			//printf("%c %c\n", s1[i], s2[j]);
		}
	}
	printf("%lld ", answer);
}

