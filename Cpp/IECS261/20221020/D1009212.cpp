#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#define MAX 40
#define Len 20
struct LongInt
{
	int MyInt[MAX];
	bool IsPositive;
	
	LongInt();
	LongInt(int);
	LongInt(const char*);
	void Init();   					
	void Init(int num);  			
	LongInt operator=(int); 		
	void Zero();  					
	void Show(); 					
	
	int Compare(LongInt b); 		
	bool operator>(LongInt b);
	bool operator<(LongInt b);
	bool operator==(LongInt b);
	
	LongInt Add(LongInt);
	LongInt operator+(LongInt); 	
	LongInt Sub(LongInt);
	LongInt operator-(LongInt); 	
	
//	HW
	LongInt Multi(LongInt);
	LongInt operator*(LongInt); 
	int Div(LongInt);
	int operator/(LongInt); 
};

int main(){
	// LongInt a = "18468284177722972105";
	// LongInt b = "57485431294651594451";  
	// LongInt a = "57485431294651594451";
	// LongInt b = "22";  
	LongInt c;
	LongInt d;
	LongInt e; 
	int div_ans; 
	
	printf("a = ");
	a.Show();

	printf("b = ");
	b.Show();

	printf("a+b = ");
	c = a + b;
	c.Show();
	
	printf("a-b = ");
	d = a - b;
	d.Show();

	printf("a*b = ");
	e = a * b;
	e.Show();

	printf("a/b =  ");
	div_ans = a / b;
	printf("%d\n", div_ans);
	
}

// 利用亂數產生一個長度小於19的值 
LongInt::LongInt() {
	Zero();
	IsPositive = true;
	// srand(time(NULL));
	// for(int i = 0; i < Len; i++) {
		// MyInt[i] = rand() % 10;
	// }
}

// 利用亂數產生一個長度小於num的值 
LongInt::LongInt(int num) {
	Zero();
	IsPositive = true;
	srand(time(NULL));
	if(num >= 0) {
		IsPositive = true;
	}else {
		IsPositive = false;
		num = num * -1;
	}
	
	for(int i = 0; i < Len; i++) {
		MyInt[i] = num % 10;
		num = num / 10;
	}
}

// 利用字串產生一個長度小於num的值 
LongInt::LongInt(const char *str) {
	int i = 0; 
	int len = strlen(str);
	Zero();
	while(str[i] != '\0') {
		MyInt[i] = str[len - 1 - i] - '0';
		i++;
	}
	if(str[0] == '-') {
		IsPositive = false;
	}else {
		IsPositive = true;
	}
}

// 產生一個長度為19的 0 
void LongInt::Zero() {
	for(int i = 0; i < MAX; i++) {
		MyInt[i] = 0;
	}
}

// 印出陣列
void LongInt::Show() {
	if(IsPositive) {
		printf(" ");
	}else {
		printf("-");
	}
	if(MyInt[21] != 0 && MyInt[0] > 0) {
		for(int i = MAX - 1; i >= 0; i--) {
			printf("%d", MyInt[i]);
		}
	}else if(MyInt[21] == 0 && MyInt[0] > 0) {
		for(int i = Len - 1; i >= 0; i--) {
			printf("%d", MyInt[i]);
		}
	}else {
		printf("%d", 0);
	}
	printf("\n");
}

// 加法
LongInt LongInt::Add(LongInt b) {
	LongInt result = 0;
	for(int i = 0; i < Len; i++) {
		result.MyInt[i] = MyInt[i] + b.MyInt[i];
	}
	
	for(int i = 0; i < Len; i++) {
		if(result.MyInt[i] >= 10) {
			result.MyInt[i+1] += result.MyInt[i] / 10;
			result.MyInt[i] = result.MyInt[i] % 10;
		}
	}

	return result;
}

// 運算子多載
LongInt LongInt::operator+(LongInt b) {
	return Add(b);
}

// 比較
int LongInt::Compare(LongInt b) {
	for(int i = Len - 1; i >= 0; i--) {
		if(MyInt[i] > b.MyInt[i])
			return 1;
		else if(MyInt[i]<b.MyInt[i])
			return -1;
	}
	return 0;
}

// 大於
bool LongInt::operator>(LongInt b) {
	if(Compare(b) == 1)
		return true;
	else
		return false;
}

// 小於
bool LongInt::operator<(LongInt b) {
	if(Compare(b) == -1)
		return true;
	else
		return false;
}

// 等於
bool LongInt::operator==(LongInt b) {
	if(Compare(b) == 0)
		return true;
	else
		return false;
}

// 減法
LongInt LongInt::Sub(LongInt b) {
	LongInt result;
	if(Compare(b) == 1 || Compare(b) == 0) {
		result.IsPositive = true;
		for(int i = 0; i < Len; i++) {
			result.MyInt[i] = MyInt[i] - b.MyInt[i];
		}
	}else {
		result.IsPositive=false;
		for(int i = 0; i < Len; i++) {
			result.MyInt[i] = b.MyInt[i] - MyInt[i];
		}
	}
	for(int i = 0; i < Len; i++) {
		if(result.MyInt[i] < 0) {
			result.MyInt[i] += 10;
			result.MyInt[i+1]--;
		} 
	}
	return result;
}

// 運算子多載
LongInt LongInt::operator-(LongInt b) {
	return Sub(b);
}

// 運算子多載
LongInt LongInt::operator=(int b) {
	return LongInt(b); 	 
}

// 乘法
LongInt LongInt::Multi(LongInt b) {
	LongInt resault;
	for(int i = 0; i < Len; i++) {
		for(int j = 0; j < Len; j++) {
			resault.MyInt[i + j] += MyInt[i] * b.MyInt[j];
			if(resault.MyInt[i + j] >= 10) {
				resault.MyInt[i + j + 1] += (resault.MyInt[i + j] / 10);
				resault.MyInt[i + j] = resault.MyInt[i + j] % 10;
			}
		}
	}
	return resault;
}

LongInt LongInt::operator*(LongInt b) {
	return Multi(b);
}

// 除法
int LongInt::Div(LongInt b) {
	int resault = 0;
	if(Compare(b) == -1) {
		return 0;
	}else if(Compare(b) == 0) {
		return 1;
	}else {
		for(int i = 0; i < Len ; i++) {
			while(Compare(b) != -1) {
				for(int j = 0; j < Len; j++) {
					MyInt[j] -= b.MyInt[j];
				}
				resault++;
			}
		}
		return resault;
	}	
}

int LongInt::operator/(LongInt b) {
	return Div(b);
}