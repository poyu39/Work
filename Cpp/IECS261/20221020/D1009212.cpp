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

// �Q�ζüƲ��ͤ@�Ӫ��פp��19���� 
LongInt::LongInt() {
	Zero();
	IsPositive = true;
	// srand(time(NULL));
	// for(int i = 0; i < Len; i++) {
		// MyInt[i] = rand() % 10;
	// }
}

// �Q�ζüƲ��ͤ@�Ӫ��פp��num���� 
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

// �Q�Φr�겣�ͤ@�Ӫ��פp��num���� 
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

// ���ͤ@�Ӫ��׬�19�� 0 
void LongInt::Zero() {
	for(int i = 0; i < MAX; i++) {
		MyInt[i] = 0;
	}
}

// �L�X�}�C
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

// �[�k
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

// �B��l�h��
LongInt LongInt::operator+(LongInt b) {
	return Add(b);
}

// ���
int LongInt::Compare(LongInt b) {
	for(int i = Len - 1; i >= 0; i--) {
		if(MyInt[i] > b.MyInt[i])
			return 1;
		else if(MyInt[i]<b.MyInt[i])
			return -1;
	}
	return 0;
}

// �j��
bool LongInt::operator>(LongInt b) {
	if(Compare(b) == 1)
		return true;
	else
		return false;
}

// �p��
bool LongInt::operator<(LongInt b) {
	if(Compare(b) == -1)
		return true;
	else
		return false;
}

// ����
bool LongInt::operator==(LongInt b) {
	if(Compare(b) == 0)
		return true;
	else
		return false;
}

// ��k
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

// �B��l�h��
LongInt LongInt::operator-(LongInt b) {
	return Sub(b);
}

// �B��l�h��
LongInt LongInt::operator=(int b) {
	return LongInt(b); 	 
}

// ���k
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

// ���k
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