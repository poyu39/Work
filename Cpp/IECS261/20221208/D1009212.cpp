#include<stdio.h>
#include<stdlib.h>
struct myTime {
	int year;
	int month;
	int day;
};
struct myCal {
	myTime t1;
	myCal();
	myCal(char* file);
	bool IsLeap(int);
	int DiffDay(myTime d_time);
	int Difftime();
	void PrintOut_Month(int year, int month);
	int GetWeekDay(int D_sum);
};

const int DaysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char WeekName[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void bar();

int main() {
	int diffD = 0;
	myCal cal("date.txt");
	printf("year:%d, Leap:%d\n", cal.t1.year, cal.IsLeap(cal.t1.year));
	diffD = cal.DiffDay(cal.t1);

	printf("1900/01/01 �� %d/%d/%d �@%d ��\n", cal.t1.year, cal.t1.month, cal.t1.day, diffD);
	printf("%d/%d/%d �P��%s, %d\n", cal.t1.year, cal.t1.month, cal.t1.day, WeekName[cal.GetWeekDay(diffD)], cal.GetWeekDay(diffD)); 
	
    printf("\n");
    bar();

    return 0;
}

int myCal::GetWeekDay(int D_sum) {
    return (1 + D_sum) % 7;
}

void bar() {
	char weekday[7][10] = {"�P����", "�P���@", "�P���G", "�P���T", "�P���|", "�P����", "�P����"};

	printf("                              �U�~��                                        \n");
    printf("******************************************************************************\n");
	for(int i = 0; i < 7; i++) {
		printf("%10s", weekday[i]);
	}
}
	
myCal::myCal() {

}

myCal::myCal(char* filename) {
	
	FILE *fptr = fopen(filename, "r");
	fscanf(fptr, "%d", &t1.year);
	fscanf(fptr, "%d", &t1.month);
	fscanf(fptr, "%d", &t1.day);
	printf("%d %d %d\n", t1.year, t1.month, t1.day);
}

bool myCal::IsLeap(int year) {
	//�褸�~ �p�G��400�����Ƥ@�w�|�~ 
	//       �p�G����400�����ơA���O��100���ƴN���|�~
	//       �p�G����400�B����100�A���O��4�����ƴN�|�~
	//       ��L�A���|�~
	if(year % 400 == 0)
		return true;
	else if(year % 100 == 0)
		return false;
	else if(year % 4 == 0)
		return true;
	else
		return false;
}

int myCal::DiffDay(myTime d_time) {
	int totalDays = 0; 
	//�p��t�X�~
    for(int i = 1900; i < d_time.year; i++){
        if(IsLeap(i))
            totalDays += 366;
        else
            totalDays += 365; 
        }
    
    //�� 
    for(int i = 1; i < d_time.month; i++) {
        totalDays += DaysOfMonth[i-1];
        if(i == 2 && IsLeap(d_time.year))
            totalDays += 1; 
    }
    //��
	
	totalDays += d_time.day - 1; 
	
	return totalDays;
}

void myCal::PrintOut_Month(int year, int month) { 
    bar();
	myCal temp;
	temp.t1.year = year;
	temp.t1.month = month;
	temp.t1.day = 1;
	int totalDays = temp.DiffDay(temp.t1);
	printf("WeekDay:%d\n", temp.GetWeekDay());
	for(int i = 0; i < temp.GetWeekDay(); i++) {
		printf("          ");
	}
	for(int i = 0; i < DaysOfMonth[temp.t1.month - 1]; i++) {
		printf("%10d", i+1);
		if((temp.GetWeekDay() + i + 1) % 7 == 0)
			printf("\n"); 
	}
	if(month==2 && IsLeap(temp.t1.year))
		printf("        29");
	
	printf("\n");	
}
