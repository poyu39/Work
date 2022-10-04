#include<stdio.h>
#include<stdlib.h>

int main() {
    int Max;
    scanf("%d", &Max);
    char star[2] = {"*"};
    for(int i = 1 ; i <= Max ; i++) {
        for(int j = 0 ; j < i ; j++){
            printf("%s", star);
        }
        printf("\n");
    }
    // system("pause");
    return 0;
}