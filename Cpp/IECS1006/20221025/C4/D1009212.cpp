#include<stdio.h>
#include<stdlib.h>

int main() {
    int i = 1, j = 1;
    do {
        j = 1;
        do {
            if (j == 7) {
                printf("%d*%d=%d", i, j, i*j);
            } else {
                printf("%d*%d=%d ", i, j, i*j);
            }
            
            j++;
        } while(j <= 7);
        if (i != 9) {
            printf("\n");
        }
        
        i++;
    } while(i <= 9);
    // system("pause");
    return 0;
}