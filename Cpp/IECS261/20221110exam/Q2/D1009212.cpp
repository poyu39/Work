#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct polynomial {
    int coef;
    int expon;
};

struct MyPoly {
    polynomial terms[MAX];
    int size;
    MyPoly();
    MyPoly(const char*);
    void ShowPoly();
    MyPoly Add(MyPoly);

};


int main() {
    MyPoly Poly1("ADT_1110a.txt");
    MyPoly Poly2("ADT_1110b.txt");
    MyPoly Ploy3;

    Poly1.ShowPoly();
    Poly2.ShowPoly();
    Ploy3 = Poly1.Add(Poly2);
    Ploy3.ShowPoly();

    system("pause");
    return 0;
}

MyPoly::MyPoly() {
    size = 0;
}

MyPoly::MyPoly(const char* filename) {
	FILE *fptr = NULL;
    // fptr = fopen(filename, "r");
    size = 0;
    if (fptr = fopen(filename, "r")) {
        while(!feof(fptr)) {
        fscanf(fptr, "%d %d", &terms[size].coef, &terms[size].expon);
        size++;
        }
    }else {
        printf("%s", "no file\n");
    }
}

void MyPoly::ShowPoly() {
    printf("%dx^%d", terms[0].coef, terms[0].expon);
	for(int i = 1; i < size; i++) {
        if(terms[i].coef < 0) {
            printf("%dx^%d", terms[i].coef, terms[i].expon);
        }else if(terms[i].coef > 0) {
            printf("+%dx^%d", terms[i].coef, terms[i].expon);
        }
    }
    printf("\n");
    // printf("\b \n");
}

MyPoly MyPoly::Add(MyPoly input) {
    MyPoly result;
    int org_index = 0;
    int input_index = 0;
    int res_index = 0;
    while(true) {
        if(terms[org_index].expon > input.terms[input_index].expon) {
            result.terms[res_index].coef = terms[org_index].coef; 
            result.terms[res_index].expon = terms[org_index].expon; 
            org_index++;
        }else if(terms[org_index].expon < input.terms[input_index].expon) {
            result.terms[res_index].coef = input.terms[input_index].coef; 
            result.terms[res_index].expon = input.terms[input_index].expon; 
            input_index++;
        }else {
            result.terms[res_index].coef = terms[org_index].coef + input.terms[input_index].coef; 
            result.terms[res_index].expon = terms[org_index].expon;
            org_index++;
            input_index++;
        }
        res_index++;
        result.size++;
        if(org_index >= size && input_index >= input.size) {
            break;
        }
    }
    return result;
}