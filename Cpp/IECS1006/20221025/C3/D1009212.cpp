#include<stdio.h>
#include<stdlib.h>

int main() {
    int max = 0, count = 0;
    scanf("%d", &max);
    for(int i = 100; i < max ; i++) {
        if(i % 3 == 0 && i % 11 == 0) {
            count += i;
        }
    }
    printf("%d", count);
    // system("pause");
    return 0;
}