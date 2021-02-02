#include<stdio.h>
#include<string.h>

int main()
{
    char s[5001] = { 0, };
    int i = 0;
    int t = 0;
    scanf("%s", s);

    while (s[i] != '\0')
    {
        if (s[i] == 'p' && s[i + 1] == 'i')
            i += 2;
        else if (s[i] == 'k' && s[i + 1] == 'a')
            i += 2;
        else if (s[i] == 'c' && s[i + 1] == 'h' && s[i + 2] == 'u')
            i += 3;
        else
        {
            t = 1;
            break;
        }

    }
    if (t == 1)printf("NO");
    else printf("YES");
}