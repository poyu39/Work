#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#include<string.h>

#define MAX 8

struct MyBin {
	int bin_num_1;
	int bin_num_2;
	long long bin_ans = 0;
	int dec_num_1;
	int dec_num_2;
	long long dec_ans = 0;
	int bin[MAX];

   	MyBin(int num_1, int num_2, char* operation) {
		for(int i = 0 ; i < MAX ; i++) {
			bin[i] = 0;
		}
		bin_num_1 = num_1;
		bin_num_2 = num_2;
		dec_num_1 = BinToDec(num_1); 
		dec_num_2 = BinToDec(num_2);
		if(strcmp(operation, "+") == 0) {
			Plus();
		}
		if(strcmp(operation, "-") == 0) {
			Sub();
		}
	} 

   	int BinToDec(int);
   	int DecToBin(int);
	void NotBin();
   	void Plus();
   	void Sub();
}; 

void OpenFile() {
    FILE *fptr = NULL;
    char file_input[MAX + 1];
	int num_1 = 0;
	int num_2 = 0;
	char operation[2];
	if (fptr = fopen("hw2.txt", "r")) {
		printf("%s\n", "file open");
		while(!feof(fptr)) {
			fscanf(fptr, "%s", file_input);
			if(strcmp(file_input, "+") != 0 && strcmp(file_input, "-") != 0) {
				if(num_1 == 0) {
					num_1 = atoi(file_input);
					printf("%d\n", num_1);
				}else if(num_2 == 0) {
					num_2 = atoi(file_input);
					printf("%d\n", num_2);
					MyBin(num_1, num_2, operation);
					num_1 = 0;
					num_2 = 0;
				}
			}else {
				strncpy(operation, file_input, 2);
				printf("%s\n", operation);
			}
		}
    }
}

int main() {
	OpenFile();
    system("pause");
	return 0;
}

//=================================================

int MyBin::BinToDec(int bin) {
	int dec = 0;
	int temp = 0;
	int i = 0;
	while(bin != 0) {
		temp = bin % 10;
		bin /= 10;
		dec += temp * pow(2, i);
		++i;
	}
	return dec;
}

int MyBin::DecToBin(int dec) {
	int i = 0;
	if(dec < 0) {
		dec *= -1;
		while(dec != 0) {
			bin[i] = dec % 2;
			dec = dec / 2;
			i++;
		}
		NotBin();
	}else {
		while(dec != 0) {
			bin[i] = dec % 2;
			dec = dec / 2;
			i++;
		}
	}
	// printf("%d", bin);
	long long n;
	for(int i = 1 ; i < MAX ; i++) {
		n += bin[i] * pow(10, i);
	}
	return n;
}

void MyBin::NotBin() {
	int i = 0;
	int j = 0;
	for(i = 0 ; i <= 8 ; i++) {
		if(bin[i] == 0)
			bin[i] = 1;
		else
			bin[i] = 0;
	}
	while(bin[j] != 0) {
		j++;
	}
	for(int i = 0 ; i <= j ; i++) {
		if(bin[i] == 0)
			bin[i] = 1;
		else
			bin[i] = 0;
	}
}

void MyBin::Plus() {
	dec_ans = dec_num_1 + dec_num_2;
	bin_ans = DecToBin(dec_ans);
	printf("%08d + %08d = %08lld (%d + %d = %d)\n", bin_num_1, bin_num_2, bin_ans, dec_num_1, dec_num_2, dec_ans);
	printf("====================\n");
}

void MyBin::Sub() {
	dec_ans = dec_num_1 - dec_num_2;
	bin_ans = DecToBin(dec_ans);
	printf("%08d - %08d = %08lld (%d - %d = %d)\n", bin_num_1, bin_num_2, bin_ans, dec_num_1, dec_num_2, dec_ans);
	printf("====================\n");
}