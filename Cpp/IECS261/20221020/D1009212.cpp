#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 40
#define Len 20

struct LongInt {
	int MyInt[MAX];
	bool IsPositive;
	
	LongInt();
	LongInt(int);
	void Init();   					//利用亂數產生一個長度小於19的值
	void Init(int num);  			//指定一個長度小於19的值
	void operator=(int); 			//運算子多載
	void Zero();  					//將本身的陣列初始為0
	void Show(); 					//顯示陣列
	
	int Compare(LongInt b); 		//比較本身跟長整數b之間何者較大，若大於b則回傳1，反之，則回傳-1
	bool operator>(LongInt b);
	bool operator<(LongInt b);
	bool operator==(LongInt b);
	
	LongInt Add(LongInt);
	LongInt operator+(LongInt); 	//運算子多載
	LongInt Sub(LongInt);
	LongInt operator-(LongInt); 	//運算子多載  
	
//	HW
//	LongInt Multi(LongInt);
//	LongInt Div(LongInt);
};

int main() {
	LongInt a(99999999);
	LongInt b(22222222); 
	LongInt c;
    LongInt d;

	printf("a = ");
	a.Show();
	
    printf("b = ");
	b.Show();
	
    c = a + b;
	printf("c = ");
	c.Show();
	
    if(a > b)
		printf("a > b\n");
	else if(a < b)
		printf("a < b\n");
	else
		printf("a == b\n");
	
    
    d = a - b;
    printf("d = ");
    d.Show();
	
    system("pause");
	return 0;
}

// 利用亂數產生一個長度小於19的值
void LongInt::Init() {
    srand(time(NULL));
    for(int i = 0; i < Len; i++) {
		MyInt[i] = rand() % 10;
	}
}

// 指定一個長度小於19的值
void LongInt::Init(int num) {
    for(int i = 0; i < num; i++) {
		MyInt[i] = rand() % 10;
	}
}

// 建構子 利用亂數產生一個長度小於19的值
LongInt::LongInt() {
	Zero();
	Init();
}

// 建構子 利用亂數產生一個長度小於19的值
LongInt::LongInt(int num) {
	Zero();
	srand(time(NULL));
	for(int i = 0; i < Len; i++)
	{
		MyInt[i] = num % 10;
		num = num / 10;
	}
	
}

// 初始化0
void LongInt::Zero() {
	for(int i = 0; i < Len; i++) {
		MyInt[i] = 0;
	}
}
void LongInt::operator=(int num) {
    for(int i = 0; i < Len; i++) {
		MyInt[i] = num;
	}
    if (num >= 0) {
        IsPositive = true;
    } else {
        IsPositive = false;
    }
}

// 印出
void LongInt::Show() {
	if (!IsPositive) {
        printf("-");
    }
    for(int i = Len - 1; i >= 0; i--) {
		printf("%d", MyInt[i]);
	}
	printf("\n");
}

// 比較本身跟長整數b之間何者較大，若大於b則回傳1，反之，則回傳-1
int LongInt::Compare(LongInt b)
{
	for(int i = Len-1; i >= 0; i--)
	{
		if(MyInt[i]>b.MyInt[i])
			return 1;
		else if(MyInt[i]<b.MyInt[i])
			return -1;
	}
	return 0;
}

// 邏輯子多載 >
bool LongInt::operator>(LongInt b) {
	if(Compare(b) == 1)
		return true;
	else
		return false;
}

// 邏輯子多載 <
bool LongInt::operator<(LongInt b) {
	if(Compare(b) == -1)
		return true;
	else
		return false;
}

// 邏輯子多載 ==
bool LongInt::operator==(LongInt b) {
	if(Compare(b) == 0)
		return true;
	else
		return false;
}

// 加法
LongInt LongInt::Add(LongInt b) {
	LongInt result=0;
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

// 運算子多載 +
LongInt LongInt::operator+(LongInt b) {
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

// 減法
LongInt LongInt::Sub(LongInt b) {
	LongInt result = 0;
    for(int i = 0; i < Len; i++) {
		result.MyInt[i] = MyInt[i] - b.MyInt[i];
	}
	for(int i = 0; i < Len; i++) {
		if(result.MyInt[i] < 0) {
			result.MyInt[i + 1] -= 1;
			result.MyInt[i] += 10;
		}
	}
	return result;
}

// 運算子多載 -
LongInt LongInt::operator-(LongInt b) {
	LongInt result;
    if (MyInt > b.MyInt) {
        for(int i = 0; i < Len; i++) {
		    result.MyInt[i] = MyInt[i] - b.MyInt[i];
	    }
        result.IsPositive = true;
    } else {
        for(int i = 0; i < Len; i++) {
		    result.MyInt[i] = b.MyInt[i] - MyInt[i];
	    }
        result.IsPositive = false;
    }
	for(int i = 0; i < Len; i++) {
		if(result.MyInt[i] < 0) {
			result.MyInt[i + 1]--;
			result.MyInt[i] += 10;
		}
	}
	return result;
}
