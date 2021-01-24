#include<stdio.h>
#include<stdlib.h>
void DrawStar(char** draw, int n, int x, int y)
{
    // 높이 3일때 
    if (n == 3)
    {

        *(*(draw + x) + y) = '*';
        *(*(draw + x + 1) + y - 1) = '*';
        *(*(draw + x + 1) + y + 1) = '*';
        *(*(draw + x + 2) + y - 2) = '*';
        *(*(draw + x + 2) + y - 1) = '*';
        *(*(draw + x + 2) + y) = '*';
        *(*(draw + x + 2) + y + 1) = '*';
        *(*(draw + x + 2) + y + 2) = '*';
    }
    else
    {
        DrawStar(draw, (n / 2), x, y);
        DrawStar(draw, (n / 2), x + (n / 2), y - (n / 2));
        DrawStar(draw, (n / 2), x + (n / 2), y + (n / 2));
    }
}
int main()
{
    char** draw = 0;
    int N;
    scanf("%d", &N);

    if (draw == NULL)
    {
        draw = (char**)malloc(N * sizeof(char*));

        for (int i = 0; i < N; i++)
        {
            draw[i] = (char*)malloc(2 * N * sizeof(char));
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
        {
            draw[i][j] = ' ';
        }
    }
    DrawStar(draw, N, 0, N - 1); // 높이,x꼭대기,y꼭대기

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2; j++)
        {
            printf("%c", draw[i][j]);
        }
        printf("\n");
    }

    if (draw != NULL)
    {
        for (int i = 0; i < N; i++)
        {
            free(draw[i]);
        }
        free(draw);
    }
    return 0;
}
