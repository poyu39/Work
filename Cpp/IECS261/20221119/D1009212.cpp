#include<stdio.h> 
#include<stdlib.h> 

#define MAX 50

struct MyBin {
	int bin;
	int dec;
	int bin_len = 0;
	int bin_array[MAX];

   	MyBin(int dec_1) {
		dec = dec_1;
	} 

   	int DecToBin();
	void NotBin();
    void Show();
}; 

int main() {
	long int num_1 = 0;

    scanf("%ld", &num_1);
    // num_1 = atoi(input);
    MyBin resault(num_1);
    resault.DecToBin();
	resault.Show();

    system("pause");
	return 0;
}

int MyBin::DecToBin() {
	if(dec < 0) {
		dec *= -1;
		while(dec != 0) {
			bin_array[bin_len] = dec % 2;
			dec = dec / 2;
			bin_len++;
		}
		NotBin();
	}else {
		while(dec != 0) {
			bin_array[bin_len] = dec % 2;
			dec = dec / 2;
			bin_len++;
		}
	}
}

void MyBin::NotBin() {
	for(int i = 0; i < bin_len ; i++) {
		if(bin_array[i] == 0)
			bin_array[i] = 1;
		else
			bin_array[i] = 0;
	}
	bin_array[0] += 1;
	for(int i = 0; i < bin_len; i++) {
		if(bin_array[i] == 2) {
			bin_array[i] = 0;
			bin_array[i+1] += 1;
		}else {
			break;
		}
	}
}

void MyBin::Show() {
	for(int i = bin_len - 1; i >= 0; i--) {
		printf("%d", bin_array[i]);
	}
}