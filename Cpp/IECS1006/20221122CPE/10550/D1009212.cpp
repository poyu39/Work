#include<stdio.h>
#include<stdlib.h>

int main() {
    int d0, d1, d2, d3;
    int degree;
    while(scanf("%d %d %d %d", &d0, &d1, &d2, &d3) != EOF) {
        if(d0 == 0 && d0 == d1 && d1 == d2 && d2 == d3) {
            return 0;
        }

        degree = 720;
        if((d1- d0) < 0) {
            degree += (d1 - d0) * 9;
        }else if((d1 - d0) > 0){
            degree += (40 - (d1 - d0)) * 9;
        }
        degree += 360;
        if((d2 - d1) < 0) {
            degree += ((d2 - d1) + 40) * 9 ;
        }else if((d2 - d1) > 0) {
            degree += (d2 - d1) * 9;
        }

        if((d3 - d2) < 0) {
            degree += (d3 - d2) * 9;
        }else if((d3 - d2) > 0) {
            degree += (40 - (d3 - d2)) * 9;
        }
        printf("%d\n", degree);
    }
    
    return 0;
}