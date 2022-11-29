#include <stdio.h>
#include <stdlib.h>
 
int main() {
    long long int num;
    long long int total;
    while(scanf("%lld", &num)) {
        total = (num + 1) * (num + 1);
        total = total * 3 / 2 - 9;
        printf("%lld\n", total);  
    }
    return 0;
}