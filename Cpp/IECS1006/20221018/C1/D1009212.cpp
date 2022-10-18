#include<stdio.h>
#include<stdlib.h>

int main() {
    char input = 2;
    int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0; 
    while(input != 'Z') {
        scanf("%c", &input);
        switch(input){
            case 'A':
                A++;
                break;
            
            case 'B':
                B++;
                break;
            
            case 'C':
                C++;
                break;
            
            case 'D':
                D++;
                break;
            
            case 'E':
                E++;
                break;
            
            case 'F':
                F++;
                break;
            
        }
    }
    int sum = A + B + C + D + E + F;
    printf("A:%d B:%d C:%d D:%d E:%d F:%d sum:%d", A, B, C, D, E, F, sum);
    // system("pause");
    return 0;
}