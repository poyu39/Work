#include<stdio.h>
#include<stdlib.h>

int main() {
    char input = 2;
    int X = 0, Y = 0;
    while(input != 'Z') {
        scanf("%c", &input);
        switch(input){
            case 'N':
                Y++;
                break;
            
            case 'S':
                Y--;
                break;
            
            case 'E':
                X++;
                break;
            
            case 'W':
                X--;
                break;
        }
    }
    printf("X:%d Y:%d", X ,Y);
    // system("pause");
    return 0;
}