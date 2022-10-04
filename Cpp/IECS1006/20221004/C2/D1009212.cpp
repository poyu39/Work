#include<stdio.h>
#include<stdlib.h>

int main() {
    int Cola, Count;
    scanf("%d", &Cola);
    Count += Cola;
    while(true) {
        Count += Cola / 3;
        Cola = Cola / 3 + Cola % 3;
        if(Cola < 3) {
            break;
        }
    }
    printf("%d\n", Count);
    //system("pause");
    return 0;
}