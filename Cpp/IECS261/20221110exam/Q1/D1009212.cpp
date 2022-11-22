#include<stdio.h>
#include<stdlib.h>

void fib(int);

int main() {
    int input;
    scanf("%d", &input);
    // printf("%d", fib(input));
    fib(input);
    system("pause");
    return 0;
}

void fib(int n) {
    int pre1 = 1, pre2 = 1;
    int result = 0;
    for(int i = 1 ; i <= n ; i++){
        if(i == 1 || i ==2) {
            if(i == 1)
                printf("fib(1)=1\n");
            if(i == 2)
                printf("fib(2)=1\n");
        }else {
            result = pre1 + pre2;
            pre2 = pre1;
            pre1 = result;
            printf("fib(%d)=%d\n", i, result);
        }
    }
}

