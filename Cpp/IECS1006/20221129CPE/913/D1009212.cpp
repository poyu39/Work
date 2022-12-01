#include <stdio.h>
#include <stdlib.h>
 
int main() {
    long long int num;
    long long int total;
    while(scanf("%lld", &num) != EOF) {
        total = num * (num + 1) / 2 + (num + 1) / 2 - 3;
        total *= 3;
        printf("%lld\n", total);  
    }
    return 0;
}