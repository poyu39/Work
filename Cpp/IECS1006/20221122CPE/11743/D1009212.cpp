#include<stdio.h>
#include<stdlib.h>

int main() {
    int num[4];
    int data;
    int sum_f[8];
    int sum_b[8];
    int sum = 0;
    int index = 0;

    scanf("%d", &data);
    for(int i = 0; i < data; i++) {
        scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);
        // printf("%d %d %d %d\n", num[0], num[1], num[2], num[3]);

        for(int j = 0; j < 4; j++) {
            sum_f[index] = num[j] / 1000 * 2;
            sum_b[index] = num[j] % 1000 / 100 ;
            sum_f[index + 1] = num[j] % 100 / 10 * 2;
            sum_b[index + 1] = num[j] % 10;
            if(sum_f[index] >= 10) {
                sum_f[index] = sum_f[index] / 10 + sum_f[index] % 10;
            }
            if(sum_f[index + 1] >= 10) {
                sum_f[index + 1] = sum_f[index + 1] / 10 + sum_f[index + 1] % 10;
            }
            if(sum_b[index] >= 10) {
                sum_b[index] = sum_b[index] / 10 + sum_b[index] % 10;
            }
            if(sum_b[index + 1] >= 10) {
                sum_b[index + 1] = sum_b[index + 1] / 10 + sum_b[index + 1] % 10;
            }

            // printf("%d %d\n", sum_f[index], sum_f[index + 1]);
            // printf("%d %d\n", sum_b[index], sum_b[index + 1]);
            sum += sum_f[index] + sum_f[index + 1] + sum_b[index] + sum_b[index + 1];
            index += 2;
        }
        // printf("%d\n", sum);
        if(sum % 10 == 0) {
            printf("Valid\n");
        }else {
            printf("Invalid\n");
        }
        sum = 0;
        index = 0;
    }
    // system("pause");
    return 0;
}