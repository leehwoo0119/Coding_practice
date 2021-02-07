#include<stdio.h>
#include<string.h>

int main()
{
    int N = 0;
    char s = 0;
    int score = 0;
    scanf("%d", &N);

    for (int i = 0; i <= N; i++)
    {
        scanf("%c", &s);
        if (s >= '0' && s <= '9')
            score += (s - '0');
        // printf("%c",s);

    }
    printf("%d ", score);
}