#include <stdio.h>
#include <stdlib.h>
#define MAX 201

struct MyString {
	char s[MAX];

    MyString();
    MyString(const char*);
	void Show(void);
    int Length(void);
    int IndexOf(const char *);
    MyString SubString(int, int);
	void Assign(const char *);
	void InsertOf(const char *, int);  
	     
    MyString operator+(const char*);
    MyString operator+(MyString);
    MyString operator+(int);
	void operator=(const char*);
};

int main() {
    MyString str = "Hello";
    str.Show();
    // printf("%d\n", str.IndexOf("o"));
    str = str + 123;
    str.Show();
    system("pause");
	return 0;
}

MyString::MyString() {
    s[0] = '\0';
}

MyString::MyString(const char *temp) {
    int i = 0;
    while(temp[i] != '\0') {
        s[i] = temp[i];
        i++;
    }
    s[i] = '\0';
}

void MyString::Show() {
    printf("%s\n", s);
}

int MyString::Length() {
    int length = 0;
    while(s[length] != '\0') {
        length++;
    }
    return length;
}

int MyString::IndexOf(const char *temp) {
    MyString MyTemp(temp);
    int temp_len = MyTemp.Length();
    int index = 0,i = 0;
    while(s[i] != '\0') {
        if(s[i] == temp[0]) {
            index = 0;
            for(int j = 0; j < temp_len; j++) {
                if(s[i + j] == temp[j]) {
                    index++;
                }
            }
            if(index == temp_len) {
                return i;
            }
        }
        i++;
    }
    return -1;
}

MyString MyString::SubString(int begin, int count) {
	
}

void MyString::Assign(const char *temp) {
	
}

void MyString::operator=(const char* temp) {
	int i = 0;
    while(temp[i] != '\0') {
        s[i] = temp[i];
        i++;
    }
}


MyString MyString::operator+(const char* temp) {
	MyString Restr;
    Restr = s;
    int i = 0;
    int s_len = Length();
    while(temp[i] != '\0') {
        Restr.s[s_len + i] = temp[i];
        i++; 
    }
    Restr.s[s_len + i] = '\0';
    return Restr;
}

MyString MyString::operator+(MyString temp) {
	MyString Restr;
    Restr = s;
    int i = 0;
    int s_len = Length();
    while(temp.s[i] != '\0') {
        Restr.s[s_len + i] = temp.s[i];
        i++; 
    }
    Restr.s[s_len + i] = '\0';
    return Restr;
}

MyString MyString::operator+(int num) {
    int temp = num;
    int count = 0;
    while(temp != 0) {
        temp /= 10;
        count++;
    }

    int a[count] = {0};
    for(int i = 0; i < count; i++) {
        a[i] = num % 10;
        num /= 10;
    }

    MyString Restr;
    Restr = s;
    int s_len = Length();
    int i = 0;
    while(a[i] != '\0') {
        Restr.s[s_len + i] = a[count - 1 - i] + '0';
        i++; 
    }
    Restr.s[s_len + i] = '\0';
    return Restr;
}

void MyString::InsertOf(const char *input, int index) {
	
}