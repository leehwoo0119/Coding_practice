#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;



void draw1(int t, int i, int a, int ss) {

    for (t = 0; t < i; t++) {
        printf(" ");
    }
    printf("*");
    for (t = 0; t < a - 2; t++) {
        printf(" ");
    }
    printf("*");
    for (t = ss; t > 0; t--) {
        printf(" ");
    }
    if (i != a - 1)printf("*");
    for (t = 0; t < a - 2; t++) {
        printf(" ");
    }
    printf("*");
    printf("\n");
}

void draw2(int a, int ss) {
    for (int i = 1; i <= a; i++)printf("*");
    for (int i = 1; i <= ss; i++)printf(" ");
    for (int i = 1; i <= a; i++)printf("*");
}
int main() {
    int t = 0;
    int a;
    int point = 0;
    int arr[1000000] = { 0, };
    scanf("%d", &a);
    for (int i = 2; i < a; i++) {
        point = 1 + 2 * (i - 2);
        arr[i - 2] = point;
    }
    //for(int i=1;i<=a*2-1;i++)draw2(i,a);
    draw2(a, 1 + 2 * (a - 2));
    printf("\n");
    for (int i = 1; i < a; i++)draw1(t, i, a, 2 * (a - 1 - i) - 1);
    for (int i = a - 2; i > 0; i--)draw1(t, i, a, 2 * (a - 1 - i) - 1);
    draw2(a, 1 + 2 * (a - 2));
}