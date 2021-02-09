#include <stdio.h>
#include <string.h>


int main() {

    char arr[101] = { 0, };
    int cnt = 0;
    scanf("%s", arr);
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == 'c')
        {
            if (arr[i + 1] == '=')
            {
                cnt++; i++;
            }

            if (arr[i + 1] == '-')
            {
                cnt++; i++;
            }

        }
        if (arr[i] == 'd')
        {
            if (arr[i + 1] == 'z')
            {
                if (arr[i + 2] == '=')
                {
                    cnt += 2; i += 2;
                }

            }
            if (arr[i + 1] == '-')
            {
                cnt++; i++;
            }

        }
        if (arr[i] == 'l')
        {
            if (arr[i + 1] == 'j')
            {
                cnt++; i++;
            }
        }
        if (arr[i] == 'n')
        {
            if (arr[i + 1] == 'j')
            {
                cnt++; i++;
            }
        }
        if (arr[i] == 's')
        {
            if (arr[i + 1] == '=')
            {
                cnt++; i++;
            }
        }
        if (arr[i] == 'z')
        {
            if (arr[i + 1] == '=')
            {
                cnt++; i++;
            }
        }
        // printf("%d\n",cnt);
    }
    printf("%d", strlen(arr) - cnt);
}