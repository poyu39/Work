#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct MyStack {
    int top;
    char a[MAX];
    void Clear();
    bool IsEmpty();
    bool IsFull();
    void Push(char);
    char Pop();
    void Show();
    MyStack() {
        top = -1;
    }
};

int main() {
    FILE* fptr = fopen("stack1110.txt", "r");
    char input[MAX];
    char temp;
    int i = 0;
    MyStack Check;
    while(!feof(fptr)) {
        fgets(input, MAX, fptr);
        // printf("%s", input); 
        Check.Push(input[0]);
        for(i = 1; i < MAX; i++) {
            if(input[i] == '\n' || input[i] == '\0') {
                break;
            } 
            // printf("%d", i);
            temp = Check.Pop();
            switch (input[i]) {
                case '{':
                case '[':
                case '(':
                    Check.Push(temp);
                    Check.Push(input[i]);
                    break;
                
                case '}':
                    if(temp != '{'){
                        i = MAX;
                    }
                    break;
                
                case ']':
                    if(temp != '['){
                        i = MAX;
                    }
                    break;
                
                case ')':
                    if(temp != '('){
                        i = MAX;
                    }
                    break;
            }
            if(Check.IsEmpty() && input[i] == '\n' || input[i] == '\0') {
                break;
            }
            // Check.Show();          
        }
        if(Check.IsEmpty() && i != MAX){
            printf("CORRECT\n");
        }else {
            printf("ERROR\n");
        }
        Check.Clear();
    }

    system("pause");
    return 0;
}

void MyStack::Clear() {
    while(top >= 0){
        Pop();
    }
}

bool MyStack::IsEmpty() {
    if(top == -1) {
        return true;
    }else {
        return false;
    }
}

bool MyStack::IsFull() {
    if(top == MAX) {
        return true;
    }else {
        return false;
    }
}

void MyStack::Push(char input) {
    top++;
    a[top] = input;
    // a[top + 1] = '\0';
}

char MyStack::Pop() {
    char result;
    result = a[top];
    // a[top] = '\0';
    top--;
    return result;
}

void MyStack::Show() {
    for(int i = 0; i <= top; i++) {
        printf("%c", a[i]);
    }
    printf("\n");
}