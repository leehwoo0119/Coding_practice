#include<stdio.h>
#include<string.h>

int main() {
    char s[101] = { 0, };


    while (scanf("%[^\n]s", s) != EOF)
    {
        getchar();
        if (strlen(s) == 0)break;
        printf("%s\n", s);
    }

}