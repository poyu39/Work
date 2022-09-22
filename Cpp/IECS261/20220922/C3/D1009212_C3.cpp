#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int re_fn(int);
int fn(int);

int main(){
    printf("use re_fn\n");
    for(int i = 2 ; i <= MAX ; i++){
        printf("%d\n", re_fn(i));
    }
    printf("use fn\n");
    for(int i = 2 ; i <= MAX ; i++){
        printf("%d\n", fn(i));
    }
    system("pause");
    return 0;
}

int re_fn(int n){
    if(n == 2){
        return 2;
    }else{
        return re_fn(n-1) + n * (n - 1);
    }
}

int fn(int n){
    int result = 0;
    for(int i = 2 ; i <= n ; i++){
        result = result + (i * (i - 1));
        // printf("%d\n", result);
    }
    return result;
}
