#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c;
    int y1, y2, y3, y4;
    printf("input a b c\n");
    scanf("%d %d %d", &a, &b, &c);
    y1 = a + b + c;
    printf("%d\n", y1);

    // scanf("%d %d %d", &a, &b, &c);
    y2 = a - b - c;
    printf("%d\n", y2);

    // scanf("%d %d %d", &a, &b, &c);
    y3 = a * b * c;
    printf("%d\n", y3);

    // scanf("%d %d %d", &a, &b, &c);
    y4 = a / b / c;
    printf("%d\n", y4);

    system("pause");
    return 0;
}