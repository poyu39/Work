#include<stdio.h>
#include<stdlib.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    for(int i = 1; i <= y; i++) {
        for(int j = 1; j <= x; j++) {
            printf("%d*%d=%d", i, j, i * j);
            if(j != x) {
                printf(" ");
            }
        }
        if(i != y) {
            printf("\n");
        }
    }
    // system("pause");
}