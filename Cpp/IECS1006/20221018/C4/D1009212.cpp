#include<stdio.h>
#include<stdlib.h>

int main() {
    int day = 0;
    scanf("%d", &day);
    switch(day){
        case 1:
            printf("���ѬO�P���@");
            break;
        case 2:
            printf("���ѬO�P���G");
            break;
            
        case 3:
            printf("���ѬO�P���T");
            break;
            
        case 4:
            printf("���ѬO�P���|");
            break;
            
        case 5:
            printf("���ѬO�P����");
            break;

        case 6:
            printf("���ѬO�P����");
            break;

        case 7:
            printf("���ѬO�P����");
            break;
        
        default:
            printf("��J���~");
            break;
    }
    // system("pause");
    return 0;
}