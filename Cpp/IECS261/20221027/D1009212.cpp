#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct MyStack {
	int top;           // 堆疊頂端
	char a[MAX];       // 堆疊主體
	
    void Show();
	bool IsEmpty();    // 判斷堆疊是否為空，是則回傳1，否則0
	bool IsFull();     // 判斷堆疊是否為滿，是則回傳1，否則0
	void Push(char);   // 將一個字元傳進堆疊中
	char Pop();        // 將一個字元從堆疊中拿出並回傳
	MyStack() {		   // 建構子
		top = -1;
	}
};

bool CheckQueue(MyStack, char*);

int main() {
	MyStack S1;

    FILE* fptr = fopen("test.txt","r");
    char input[10];
    while(!feof(fptr)) {
        fscanf(fptr, "%s", &input);
        // printf("%s\n", input);
        if (CheckQueue(S1, input)){
            printf("CORRNET\n");
        }else {
            printf("ERROR\n");
        }
    }
    S1.Show();
    system("pause");

	return 0;	
}

bool CheckQueue(MyStack S1, char* input) {
    char read;
    for(int i = 0; i < MAX; i++) {
        printf("%c\n", input[i]);
        if(input[i] == '(' || input[i] == '[' || input[i] == '{') {
            S1.Push(input[i]);
        }else {
            read = S1.Pop();
            if(input[i] == ')' && read != '(') {
                return false;
            }
            if(input[i] == ']' && read != '[') {
                return false;
            }
            if(input[i] == '}' && read != '{') {
                return false;
            }
            S1.Push(read);
        }
    }
    if (S1.IsEmpty()) {
        return true;
    }else {
        return false;
    }
}

void MyStack::Show() {
    for(int i = 0; i <= top; i++) {
        printf("%c", a[i]);
    }
}

// 判斷是否為空
bool MyStack::IsEmpty() {
	if(top == -1) {
        return true;
    }else {
        return false;
    }
}

// 判斷是否為滿
bool MyStack::IsFull() {
	if(top == 9) {
        return true;
    }else {
        return false;
    }
}

// 將一個字元傳進堆疊中
void MyStack::Push(char ch) {
    top++;
    a[top] = ch;
}

// 將一個字元從堆疊中拿出並回傳
char MyStack::Pop() {
    char resault;
    if(IsEmpty()){
        resault = NULL;
    }else {
        resault = a[top];
        top--;
    }
	return resault;
}
