#include<stdio.h>
#include<string.h>

int main()
{
    char s[51] = { 0, };
    int score = 10;
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (i != 0)
        {
            if (s[i] != s[i - 1])score += 10;
            else score += 5;
        }

    }
    printf("%d ", score);
}