#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int last[n] = {0, 1};
    for(int i = 0; i < n; i++) {
        if (i < 2) {
            printf("%d\n", last[i]);
        }else {
            printf("%d\n", last[i - 2] + last[i - 1]);
            last[i] = last[i - 2] + last[i - 1];
        }
    }
    // system("pause");
}
