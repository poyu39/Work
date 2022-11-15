#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    int temp;
    int input;
    int now_pm;
    int last_pm;
    bool order = true;
    scanf("%d", &n);
    int output[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        now_pm = 0;
        last_pm = 0;
        for(int j = 0; j < 9; j++) {
            scanf("%d", &input);
            now_pm = temp - input;
            if(now_pm > 0 && last_pm < 0) {
                order = false;
            }
            if(now_pm < 0 && last_pm > 0) {
                order = false;
            }
            last_pm = now_pm;
            temp = input;
        }
        if(order == true) {
            output[i] = 1;
        }else if(order == false){
            output[i] = -1;
            order = true;
        }
    }
    printf("Lumberjacks:\n");
    for(int i = 0; i < n; i++) {
        if(output[i] == 1) {
            printf("Ordered\n");
        }else if(output[i] == -1){
            printf("Unordered\n");
        }
    }
    // system("pause");
    return 0;
}