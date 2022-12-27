#include <stdio.h>
#include <stdlib.h>

int main() {
    int data_count;
    int doomsday[5][2] = {
        {4, 4},
        {6, 6},
        {8, 8},
        {10, 10},
        {12, 12}
    };
    int per_month_day[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d", &data_count);
    for (int i = 0; i < data_count; i++) {
        int month, day, error_day = 0, week;
        scanf("%d %d", &month, &day);
        int month_index = 0;
        while (month > doomsday[month_index][0]) {
            month_index++;
        }
        
        for (int j = 1; j <= doomsday[month_index][0] - month; j++) {
            error_day += per_month_day[doomsday[month_index][0] - j];
        }
        
        error_day = error_day + (doomsday[month_index][1] - day);
        week = error_day % 7;
        if (week > 0) {
            week = 7 - week;
        } else if (week < 0) {
            week *= -1;
        }
        
        switch (week) {
        case 0:
            printf("Monday\n");
            break;
        
        case 1:
            printf("Tuesday\n");
            break;
        
        case 2:
            printf("Wednesday\n");
            break;
        
        case 3:
            printf("Thursday\n");
            break;
        
        case 4:
            printf("Friday\n");
            break;
        
        case 5:
            printf("Saturday\n");
            break;
        
        case 6:
            printf("Sunday\n");
            break;
        }
    }
    //system("pause");
}