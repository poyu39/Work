#include<stdio.h>
#include<stdlib.h>

int main() {
    int First, Last, Com;
    int Total = 0;
    scanf("%d %d %d", &First, &Last, &Com);
    for (int i = First ; i <= Last ; i = i + Com) {
        Total += i;
        printf("%d\n", i);
    }
    printf("%d", Total);
    // system("pause");
    return 0;
}