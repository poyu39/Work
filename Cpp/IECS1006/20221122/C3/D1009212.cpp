#include<stdio.h>
#include<srdlib.h>

int main() {
    int init;
    int d0, d1, d2;
    int degree = 1080;
    while(scanf("%d %d %d %d", &init, &d0, &d1, &d2) != EOF) {
        if((d0 - init) >= 0) {
            degree += (d0 - init);
        }else {
            degree += abs(d0 - init) + 360;
        }

        if((d1 - d0) >= 0) {
            degree += (d1 - d0);
        }else {
            degree += abs(d1 - d0) + 360;
        } 

        if((d2 - d0) >= 0) {
            degree += (d1 - d0);
        }else {
            degree += abs(d1 - d0) + 360;
        } 

    }
    
}