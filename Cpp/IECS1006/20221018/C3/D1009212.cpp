#include<stdio.h>
#include<stdlib.h>

int main() {
    int value = 0;
    scanf("%d", &value);
    switch(value / 10){
        case 10:
            printf("A");
            break;
        case 9:
            printf("A");
            break;
            
        case 8:
            printf("B");
            break;
            
        case 7:
            printf("C");
            break;
            
        case 6:
            printf("D");
            break;

        default:
            printf("E");
            break;
    }
    //system("pause");
    return 0;
}