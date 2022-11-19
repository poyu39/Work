#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct MyStack {
	int top;           
	char a[MAX];    

    void Show();
    void Clear();
	bool IsEmpty();    
	bool IsFull();     
	void Push(char);   
	char Pop();        
	MyStack() {		   
		top = -1;
	}
};

void ReadFile(char*, const char*);

void DDCut(char*);

int main() {
    char input[MAX];

    scanf("%s", input);
    DDCut(input);
    // system("pause");
	return 0;	
}

void DDCut(char* input) {
    MyStack dd_str;
    MyStack dd_str_pre;
    int index = 0;
    int check = 0;
    while(input[index] != '\0') {
        check = index;
        dd_str.a[0] = input[index];
        while(input[check] != '\0') {
            if(dd_str.a[0] != input[check]) {
                printf("%c", input[check]);
                dd_str.Push(input[check]);
            }else {
                if(dd_str_pre.top >= dd_str.top) {
                    dd_str.Clear();
                }else {
                    dd_str_pre.Push(dd_str.Pop());
                }
                break;
            }
            check++;
        }
        index++;
    }
    dd_str_pre.Show();
}

void MyStack::Show() {
    for(int i = 0; i <= top; i++) {
        printf("%c", a[i]);
    }
    printf("\n");
}

void MyStack::Clear() {
    if(!IsEmpty())
        Pop();
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
	if(top == MAX) {
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
    if(!IsEmpty()){
        resault = a[top];
        top--;
    }
	return resault;
}
