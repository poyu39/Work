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

void EsCut(char*);

int main() {
    char input[MAX];
    char file_name[] = "input.txt";
    // ReadFile(input, "input.txt");
    
    FILE* fptr = fopen(file_name,"r");
    int len = 0;
    while(!feof(fptr)) {
        fgets(input, MAX, fptr);
        EsCut(input);
    }
    system("pause");
	return 0;	
}

void ReadFile(char* input, const char* file_name) {
    FILE* fptr = fopen(file_name,"r");
    int len = 0;
    while(!feof(fptr)) {
        fgets(input, MAX, fptr);
    }
}

void EsCut(char* input) {
    MyStack es_str;
    int count = 0;
    for(int i = 0; i <= MAX; i++) {
        if(input[i] == '\n' || input[i] == '\0')
            break;
        es_str.Push(input[i]);
        if(count > 0)
            count++;
        if(input[i] == 'e') {
            count = 1;
        }else if(input[i] == 's') {
            for(int j = 0; j < count; j++)
                es_str.Pop();
            count = 0;
        }
    }
    es_str.Show();
    es_str.Clear();
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
