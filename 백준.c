#include<stdio.h>
#include<string.h>

int main()
{
    int N = 0;
    char K[70] = { 0, };

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", K);
        if (K[strlen(K) - 1] % 2 != 0)printf("odd\n");
        if (K[strlen(K) - 1] % 2 == 0)printf("even\n");
    }
}