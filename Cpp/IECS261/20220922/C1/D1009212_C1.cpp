#include<stdio.h>
#include<stdlib.h>

int re_fact(int);
int fact(int);

int main(){
    printf("use re_fact\n");
    for(int i = 1 ; i <= 10 ; i ++){
        printf("%2d! = %d\n", i, re_fact(i));
    }
    printf("use fact\n");
    for(int i = 1 ; i <= 10 ; i ++){
        printf("%2d! = %d\n", i, fact(i));
    }
    system("pause");
    return 0;
}

int re_fact(int n){
    if(n == 1){
        return 1;
    }else{
        return n * re_fact(n - 1);
    }
}

int fact(int n){
    int result = 1;
    for(int i = 1 ; i <= n ; i++){
        result = result * i;
    }
    return result;
}
