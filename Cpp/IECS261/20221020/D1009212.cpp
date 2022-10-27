#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#define MAX 40
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
	LongInt Div(LongInt);
	LongInt operator/(LongInt); 
};

int main(){
	LongInt a = "18468284177722972105";
	LongInt b = "57485431294651594451";  
	// LongInt a = "1000000";
	// LongInt b = "2";  
	LongInt c;
	LongInt d;
	LongInt e; 
	LongInt f; 
	
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

	printf("a/b = ");
	f = a.Div(b);
	f.Show();
	
	system("pause");
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

// ���ͤ@�Ӫ��פp��num���� 
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
	
	for(int i = 0; i < MAX; i++) {
		MyInt[i] = num % 10;
		num = num / 10;
	}
}

// �Q�Φr�겣�ͤ@�ӭ� 
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

// ���ͤ@�Ӫ��׬�40�� 0 
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
	int temp = 0;
	while(MyInt[MAX - 1 - temp] == 0) {
		temp++;
	}
	for(int i = MAX - 1 - temp; i >= 0; i--) {
		printf("%d", MyInt[i]);
	}
	if(MyInt[39] == 0) {
		printf("%d", 0);
	}
	printf("\n");
}

// �[�k
LongInt LongInt::Add(LongInt b) {
	LongInt result = 0;
	for(int i = 0; i < MAX; i++) {
		result.MyInt[i] = MyInt[i] + b.MyInt[i];
	}
	
	for(int i = 0; i < MAX; i++) {
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
	for(int i = MAX - 1; i >= 0; i--) {
		if(MyInt[i] > b.MyInt[i])
			return 1;
		else if(MyInt[i] < b.MyInt[i])
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
		for(int i = 0; i < MAX; i++) {
			result.MyInt[i] = MyInt[i] - b.MyInt[i];
		}
	}else {
		result.IsPositive=false;
		for(int i = 0; i < MAX; i++) {
			result.MyInt[i] = b.MyInt[i] - MyInt[i];
		}
	}
	for(int i = 0; i < MAX; i++) {
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
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
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
LongInt LongInt::Div(LongInt b) {
	LongInt resault = 0;
	LongInt copy = 0;
	LongInt temp = 0;
	long int err_len = 0;
	int this_len = 40, b_len = 40;
	copy = Multi(1);
	if(copy.Compare(b) == 0){
		resault = 1;
		return resault;
	}else if(copy.Compare(b) == -1) {
		resault = 0;
		return resault;
	}
	for(int i = MAX - 1; i >= 0; i--) {
		if(MyInt[i] == 0) {
			this_len-- ;
		}else {
			break;
		}
	}
	for(int i = MAX - 1; i >= 0; i--) {
		if(b.MyInt[i] == 0) {
			b_len--;
		}else {
			break;
		}
	}
	err_len = this_len - b_len;
	for(long int i = err_len; i >= 0; i--) {
		temp = b.Multi(pow(10, i));
		while(copy.Compare(temp) >= 0) {
			copy = copy.Sub(temp);
			resault = resault + pow(10, i);
		}	
	}
	return resault;
}

LongInt LongInt::operator/(LongInt b) {
	return Div(b);
}