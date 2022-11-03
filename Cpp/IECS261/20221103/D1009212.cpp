#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef enum {op, val} mytype;

struct data {
	mytype type;
	int value;
	char oper;
	int priority;
};

struct SplitData {
	data item[MAX];
	data postitem[MAX];
	int count;
	void Split(char*);
	void ShowInfix();	
	void InfixToPost();
	void ShowPostfix(); 	
};

struct MyStack {
	data a[MAX];
	int top;
	bool IsEmpty();
	bool IsFull();
	void Push(data da);
	data Pop();
	data Top();
	MyStack() {
		top=-1;
	}
};

void read_file(char* input, const char* file_name) {
    FILE* fptr = fopen(file_name,"r");
    int len = 0;
    while(!feof(fptr)) {
        fscanf(fptr, "%c", &input[len]);
        len++;
    }
    /*
    for(int i = 0; i <= len; i++) {
        printf("%c", input[i]);    
    }
    */
}

int main() {
    char input[80];
    read_file(input, "1103.txt");
    SplitData DataInFix;
    DataInFix.Split(input);
    DataInFix.ShowInfix();
    system("pause");
	return 0;
} 

bool MyStack::IsEmpty() {
	if(top == -1)
		return true;
	else
		return false;
}

bool MyStack::IsFull() {
	if(top == MAX - 1)
		return true;
	else
		return false;
}

void MyStack::Push(data da) {
	if(IsFull())
		printf("The STACK is full");
	else
		a[++top] = da;
}

data MyStack::Pop() {
	if(IsEmpty())
		printf("The STACK is empty");
	else
		return a[top--];
}

data MyStack::Top() {
	if(IsEmpty())
		printf("The STACK is empty");
	else
		return a[top];
}

void SplitData::Split(char *str) {
	count = 0;
	int i = 0, j = 0;
	char temp[MAX];
	while(str[i] != '\0') {
		switch(str[i]) {
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
			case ')':
                if(j != 0) {
                temp[j] = '\0';
                item[count].type = val;
                item[count].value = atoi(temp);
                printf("%d\n", item[count].value);
                j = 0;
                count++;
                }
                
                item[count].type = op;
                item[count].oper = str[i];
                printf("%c\n", item[count].oper);
                count++;
                break;
			default:
				temp[j] = str[i];
				j++;
		}
		i++;
	}

	if(j != 0) {
		temp[j] = '\0';
	 	item[count].type = val;
	 	item[count].value = atoi(temp);
	 	printf("%d\n", item[count].value);
	 	j = 0;
	 	count++;
	}

	for(int i = 0; i < count; i++) {
		if(item[i].oper == '+' || item[i].oper == '-')
			item[i].priority = 1;
		else if(item[i].oper == '*' || item[i].oper == '/')
			item[i].priority = 2;
	}
}

void SplitData::ShowInfix() {
	for(int i = 0; i < count; i++) {
		if(item[i].type == val)
			printf("%d", item[i].value);
		else
			printf("%c", item[i].oper);
	}
}