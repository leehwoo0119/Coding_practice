#include<stdio.h>
#include<string.h>

int main() {
    char s[101] = { 0, };
    int cnt = 0;
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            cnt++;
    }
    printf("%d", cnt);
}