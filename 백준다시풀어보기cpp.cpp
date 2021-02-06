#include<stdio.h>
#include<string.h>

int main() {
    int N = 0;
    char s[81] = { 0, };
    int cnt = 0;
    int score = 0;

    scanf("%d", &N);

    for (int j = 0; j < N; j++)
    {
        score = 0; cnt = 0;
        scanf("%s", s);
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] == 'O')
            {
                cnt++;
            }
            if (s[i] == 'X')
            {
                cnt = 0;
            }
            score += cnt;
        }
        printf("%d\n", score);
    }


}