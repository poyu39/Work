#include <stdio.h>
#include <stdlib.h>
#define MAX 150

struct MyStack {
	int top;           // 堆疊頂端
	char a[MAX];       // 堆疊主體
	
    void Show();
    void Clear();
	bool IsEmpty();    // 判斷堆疊是否為空，是則回傳1，否則0
	bool IsFull();     // 判斷堆疊是否為滿，是則回傳1，否則0
	void Push(char);   // 將一個字元傳進堆疊中
	char Pop();        // 將一個字元從堆疊中拿出並回傳
	MyStack() {		   // 建構子
		top = -1;
	}
};

void read_file(char* input, const char* file_name) {
    FILE* fptr = fopen(file_name,"r");
    int len = 0;
    while(!feof(fptr)) {
        fscanf(fptr, "%c", &input[len]);
        len++;
    }
    input[len] = '\0';
    /*
    for(int i = 0; i <= len; i++) {
        printf("%c", input[i]);    
    }
    */
}
void es_cut(char*, int*);

int main() {
	MyStack es_str;
    char input[100];
    read_file(input, "input.txt");
    int str_count = 0;
    int count = 0;
    int str = 2;

    for(int i = 0; i <= str; i++) {
        MyStack es_str;
        for(int j = str_count; j <= MAX; j++) {
            if(input[j] == '\n' || input[j] == '\0') {
                break;
                str++;
            }
            es_str.Push(input[j]);
            if(count > 0)
                count++;
            
            if(input[j] == 'e') {
                count = 1;
            }else if(input[j] == 's') {
                for(int k = 0; k < count; k++) {
                    es_str.Pop();
                }
                count = 0;
            }
            str_count++;
        }
        es_str.Show();
        es_str.Clear();
        str_count++;
    }

    system("pause");

	return 0;	
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
