#include<stdio.h>
#include<stdlib.h>

int main() {
    int a, b, c;
    scanf("%d %d", &a, &b);
    int a_ans = a;
    int b_ans = b;
    while( b != 0 )
    {
        c = b;
        b = a % b;
        a = c;
    }
    printf("%d", a_ans * b_ans / a);

    // system("pause");
    return 0;
}