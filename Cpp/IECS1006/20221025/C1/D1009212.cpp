#include<stdio.h>
#include<stdlib.h>

int main() {
    int a, b, c;
    scanf("%d %d", &a, &b);
    while( b != 0 )
    {
        c = b;
        b = a % b;
        a = c;
    }
    printf("%d", a);

    // system("pause");
    return 0;
}