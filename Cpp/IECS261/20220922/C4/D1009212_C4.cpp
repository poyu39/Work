#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int fn(int);

int main(){
    printf("f(%d) = %d", MAX, fn(MAX));
    system("pause");
    return 0;
}

int fn(int n){
    if(n == 0){
        return 3;
    }else{
        return 2 * fn(n - 1) - 5;
    }
}