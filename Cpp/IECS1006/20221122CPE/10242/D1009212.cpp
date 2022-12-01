#include<stdio.h>
#include<stdlib.h>

int main() {
    float x0,y0;
    float x1,y1;
    float x2,y2;
    float x3,y3;

    float x_f, y_f;
    float x_middle, y_middle;
    float x_b, y_b;

    float x_ans,y_ans;

    while(scanf("%f %f %f %f %f %f %f %f", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
        // scanf("%f %f %f %f %f %f %f %f", &x0, &y0, &x1, &y1, &x2, &y2, &x3, &y3)
        // printf("x0: %.3f, y0: %.3f, x1: %.3f, y1: %.3f, x2: %.3f, y2: %.3f, x3: %.3f, y3: %.3f\n", x0, y0, x1, y1, x2, y2, x3, y3);
        
        if(x0 == x1 && y0 == y1) {
            x_f = x2;
            y_f = y2;
            x_b = x3;
            y_b = y3;
            x_middle = x0;
            y_middle = y0;
        }
        if(x0 == x2 && y0 == y2) {
            x_f = x1;
            y_f = y1;
            x_b = x3;
            y_b = y3;
            x_middle = x0;
            y_middle = y0;
        }
        if(x0 == x3 && y0 == y3) {
            x_f = x1;
            y_f = y1;
            x_b = x2;
            y_b = y2;
            x_middle = x0;
            y_middle = y0;
        }

        if(x1 == x2 && y1 == y2) {
            x_f = x0;
            y_f = y0;
            x_b = x3;
            y_b = y3;
            x_middle = x1;
            y_middle = y1;
        }
        if(x1 == x3 && y1 == y3) {
            x_f = x0;
            y_f = y0;
            x_b = x2;
            y_b = y2;
            x_middle = x1;
            y_middle = y1;
        }

        if(x2 == x3 && y2 == y3) {
            x_f = x0;
            y_f = y0;
            x_b = x1;
            y_b = y1;
            x_middle = x2;
            y_middle = y2;
        }

        x_ans = (x_f + x_b) - x_middle;
        y_ans = (y_f + y_b) - y_middle;
        
        printf("%.3f %.3f\n", x_ans, y_ans);
    }
    // system("pause");
    return 0;
}