#include<stdio.h>
#include<stdlib.h>

int re_fib(int);
int fib(int);

#define MAX 10

int main(){
    printf("use re_fib\n");
    for(int i = 1 ; i <= MAX ; i++){
        printf("f(%d) = %d\n", i, re_fib(i));
    }
    printf("use fib\n");
    for(int i = 1 ; i <= MAX ; i++){
        printf("f(%d) = %d\n", i, fib(i));
    }
    system("pause");
    return 0;
}

int re_fib(int n){
    if(n == 1 || n ==2){
        return 1;
    }else{
        return re_fib(n - 1) + re_fib(n - 2);
    }
}

int fib(int n){
    int pre1 = 1, pre2 = 1;
    int result = 0;
    if(n == 1 || n ==2){
        return 1;
    }else{
        for(int i = 3 ; i <= n ; i++){
            result = pre1 + pre2;
            pre2 = pre1;
            pre1 = result;
        }
        return result;
    }
}