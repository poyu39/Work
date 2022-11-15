#include<stdio.h>
#include<stdlib.h>

int main() {
    int input;
    int temp;
    int n;
    bool jolly = true;
    while(scanf("%d", &n) != EOF) {
        scanf("%d", &temp);
        for(int i = 1; i < n; i++) {
            scanf("%d", &input);
            if(abs(input - temp) >= n || abs(input - temp) < 1) {
                jolly = false;
                for(int j = i; j < n; j++) {
                    scanf("%d", &input);
                }
                break;
            }
            temp = input;
        }
        if(jolly) {
            printf("Jolly\n");
        }else {
            printf("Not jolly\n");
            jolly = true;
        }
    }
    system("pause");
    return 0;
}