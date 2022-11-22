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
	data preitem[MAX];
	data item[MAX];
	data postitem[MAX];
	int preitem_count;
	int item_count;
	int postitem_count;
	void Split(char*);
	void Clear();
	void ShowInfix();	
	void InfixToPre();

	void InfixToPost();
	float PostOperation();
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
		top = -1;
	}
};

int main() {
    char input[MAX];
	SplitData Data;
	FILE* fptr = fopen("1103.txt","r");
	printf("InFix To Post\n");
    while(!feof(fptr)) {
		printf("--------------------\n");
        fgets(input, MAX, fptr);
		Data.Split(input);
		Data.InfixToPost();
    	// Data.ShowInfix();
		Data.ShowPostfix();
		printf("result: %.2f\n", Data.PostOperation());
    }
	printf("--------------------\n");

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
	item_count = 0;
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
					item[item_count].type = val;
					item[item_count].value = atoi(temp);
					j = 0;
					item_count++;
                }
                item[item_count].type = op;
                item[item_count].oper = str[i];
                item_count++;
                
				break;

			default:
				temp[j] = str[i];
				j++;
				break;
		}
		i++;
	}

	if(j != 0) {
		temp[j] = '\0';
	 	item[item_count].type = val;
	 	item[item_count].value = atoi(temp);
	 	j = 0;
	 	item_count++;
	}

	int bracket = 0;
	for(int i = 0; i < item_count; i++) {
		if(item[i].oper == '+' || item[i].oper == '-')
			item[i].priority = 1 + bracket;
		else if(item[i].oper == '*' || item[i].oper == '/')
			item[i].priority = 2 + bracket;
		else if(item[i].oper == '(' || item[i].oper == ')')
			item[i].priority = -1;
		
		if(item[i].oper == '(') {
			bracket+=2;
		}else if(item[i].oper == ')') {
			bracket-=2;
		}
	}
}

void SplitData::ShowInfix() {
	for(int i = 0; i < item_count; i++) {
		if(item[i].type == val)
			printf("%d", item[i].value);
		else
			printf("%c", item[i].oper);
	}
	printf("\n");
}

void SplitData::InfixToPost() {
	MyStack s;
	postitem_count = 0;
	int i = 0 , j = 0;
	for(int i = 0; i < item_count; i++) {
		if(item[i].type == val) {
			postitem[j]= item[i];
			j++;
		}else {
			if(item[i].oper != '(' && item[i].oper != ')') {
				if(s.IsEmpty())
					s.Push(item[i]);
				else{
					while(s.a[s.top].priority >= item[i].priority && !s.IsEmpty()) {
						if(s.a[s.top].priority > 0) {
							postitem[j] = s.Pop();
						}else {
							s.Pop();
						}
						j++;
					}
					s.Push(item[i]);
				}
			}
		}
	}
	while(!s.IsEmpty()) {
		postitem[j] = s.Pop();
		j++;
	}
	postitem_count = j;
}

float SplitData::PostOperation() {
	float ans = 0;
	float temp = 0;
	int value_count = 0;
	for(int i = 0; i < postitem_count; i++) {
		if(postitem[i].type == op) {
			if(value_count == 1) {
				switch(postitem[i].oper) {
					case '+':
						ans += postitem[i-1].value;
						break;
					case '-':
						ans -= postitem[i-1].value;
						break;
					case '*':
						ans *= postitem[i-1].value;
						break;
					case '/':
						ans /= postitem[i-1].value;
						break;
				}
			}else if(value_count == 2) {
				switch(postitem[i].oper) {
					case '+':
						temp = postitem[i-2].value + postitem[i-1].value;
						break;
					case '-':
						temp = postitem[i-2].value - postitem[i-1].value;
						break;
					case '*':
						temp = postitem[i-2].value * postitem[i-1].value;
						break;
					case '/':
						temp = postitem[i-2].value / postitem[i-1].value;
						break;
				}
				if(postitem[i+1].type == op) {
					switch(postitem[i+1].oper) {
						case '+':
							ans += temp;
							break;
						case '-':
							ans -= temp;
							break;
						case '*':
							ans *= temp;
							break;
						case '/':
							ans /= temp;
							break;
					}
					i++;
				}else {
					ans += temp;
				}
			}
			value_count = 0;
			temp = 0;
		}else {
			value_count++;
		}
		// printf("%d ", postitem[i].type);
		// printf("%2f\n", ans);
	}
	return ans;
}

void SplitData::ShowPostfix() {
	for(int i = 0; i < postitem_count; i++) {
		if(postitem[i].type == val)
			printf(" %d ", postitem[i].value);
		else
			printf("%c", postitem[i].oper);
	}
	printf("\n");
}

void SplitData::InfixToPre() {
	MyStack s;
	preitem_count = 0;
	int i = 0, j = 0;
	for(int i = 0; i < item_count; i++) {
		if(item[i].type == val) {
			postitem[j] = item[i];
			j++;
		}else {
			if(item[i].oper != '(' && item[i].oper != ')') {
				if(s.IsEmpty())
					s.Push(item[i]);
				else{
					while(s.a[s.top].priority >= item[i].priority && !s.IsEmpty()) {
						if(s.a[s.top].priority > 0) {
							postitem[j] = s.Pop();
						}else {
							s.Pop();
						}
						j++;
					}
					s.Push(item[i]);
				}
			}
		}
	}
	while(!s.IsEmpty()) {
		postitem[j] = s.Pop();
		j++;
	}
	postitem_count = j;
}
