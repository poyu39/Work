#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, tot = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n ; i++) {
        tot = tot * i;
    }
    printf("%d\n", tot);
    // system("pause");
}