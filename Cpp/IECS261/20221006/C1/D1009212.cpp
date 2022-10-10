#include <stdio.h>
#include <stdlib.h>
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
	MyPoly SingleMult(polynomial);           
	int Lead_Exp();                 
	void Attach(int, int);          
	void Remove(int);              

	// MyPoly Mult(MyPoly);         
};

int main() {
    MyPoly poly1("B1.txt");
    MyPoly poly2("B2.txt");
    MyPoly poly3;
    
    // poly1.ShowPoly();    
    // poly2.ShowPoly();    
    // printf("poly1 lead expon = %d\n", poly1.Lead_Exp());

    // polynomial t;
    // t.coef = 10;
    // t.expon = 10;

    poly3 = poly1.Add(poly2);
    poly3.ShowPoly();    

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
	for(int i = 0; i < size; i++) {
        printf("%dx^%d+", terms[i].coef, terms[i].expon);
    }
    printf("\b \n");
}

MyPoly MyPoly::SingleMult(polynomial p) {
	MyPoly result;
    for(int i = 0; i < size; i++) {
        result.terms[i].coef = terms[i].coef * p.coef;
        result.terms[i].expon = terms[i].expon + p.expon;
        result.size++;
    }
    return result;
}

MyPoly MyPoly::Add(MyPoly B) {
	MyPoly result;
	int a_index = 0, b_index = 0;
	
	while(a_index < size && b_index < B.size) {
		if(terms[a_index].expon < B.terms[b_index].expon)
		{
			result.terms[result.size] = B.terms[b_index];
			result.size++;
			b_index++;
		}
		else if(terms[a_index].expon == B.terms[b_index].expon) {
			int result_coef=terms[a_index].coef + B.terms[b_index].coef;
			if(result_coef != 0) {
				result.terms[result.size].coef = result_coef;
				result.terms[result.size].expon = B.terms[b_index].expon;
			}
			result.size++;
			a_index++;
			b_index++;
		}else {
			result.terms[result.size]=terms[a_index];
			result.size++;
			a_index++;
		}
	}
	for(; a_index < size; a_index++) {
		result.terms[result.size] = terms[a_index];
		result.size++;
	}
	for(; b_index < size; b_index++) {
		result.terms[result.size] = B.terms[b_index];
		result.size++;
	}
	return result;
}

int MyPoly::Lead_Exp() {
	return terms[0].expon;
}

void MyPoly::Attach(int coef, int expon)	 {

    
}
void MyPoly::Remove(int num) {
	
}

// MyPoly MyPoly::Mult(MyPoly B)
// {
    
// }
