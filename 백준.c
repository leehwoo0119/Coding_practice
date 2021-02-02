#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
{
    char s = 0;
    int cnt = 0;
    // while (scanf("%[^\n]s", s) != EOF)
    for (int i = 0; i < 8; i++)
    {

        for (int j = 0; j < 8; j++)
        {
            scanf("%c", &s);
            if (s == 'F')
            {
                if (i % 2 == 0)
                    if (j % 2 == 0)cnt++;
                if (i % 2 == 1)
                    if (j % 2 == 1)cnt++;
            }

        }
        scanf("%c", &s);//¶ç¾î¾²±â
    }

    printf("%d", cnt);
}
