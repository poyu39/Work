#include <stdio.h>
#include <stdlib.h>

int main() {
    int input_count;
    scanf("%d", &input_count);
    for (int i = 0; i < input_count; i++) {
        getchar();
        int A = 0;
        int F = 0;
        scanf("%d", &A);
        scanf("%d", &F);
        //printf("%d, %d\n", A, F);
        for (int i = 1; i <= F; i++) {
            for (int j = 1; j <= A; j++) {
                for (int k = 0; k < j; k++) {
                    printf("%d", j);
                }
                printf("\n");
            }
            for (int j = A - 1; j > 0; j--) {
                for (int k = 0; k < j; k++) {
                    printf("%d", j);
                }
                printf("\n");
            }  
            printf("\n");
        }
    }
    //system("pause");
}