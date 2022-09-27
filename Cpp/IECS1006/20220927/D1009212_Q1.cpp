#include <stdio.h>
#include <stdlib.h>

int main(){
    int value;
    scanf("%d", &value);
    if(value >= 90){
        printf("A");
    }else if(value >= 80){
        printf("B");
    }else if(value >= 70){
        printf("C");
    }else if(value >= 60){
        printf("D");
    }else{
        printf("F");
    }
    return 0;
}