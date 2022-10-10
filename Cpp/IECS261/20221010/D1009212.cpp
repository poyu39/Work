#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void ShowUI();
void ReadUI(int);

struct polynomial{
	int coef;                       // 多項式的係數
	int expon;                      // 多項式的指數
}; 
 
struct MyPoly { 
	polynomial terms[MAX];          // 多項式陣列
	int size;                       // 多項式大小
	MyPoly();                       // 建構子 初始化 size = 0
    void ReadFile(const char*);     // 讀入檔案

    void ShowPoly();                // 印出多項式內容
	MyPoly Add(MyPoly);             // 多項式相加
	void SingleMult(polynomial);    // 將多項式的係數和項次乘上數值
	int Lead_Exp();                 // 回傳多項式中最大指數的次方
    void Attach(int, int);          // 新增 1 個項式到多項式中
	void Remove(int);               // 刪除多項式中的某一指數
    MyPoly Mult(MyPoly);            // 多項式相乘
};

int main() {
    MyPoly poly1;
    MyPoly poly2;
    MyPoly add_result;
    MyPoly mult_result;
    int option = 0;
    
    ShowUI();
    printf("\n");
    while(scanf("%d", &option)) {
        switch (option) {
        case 1:
            poly1.ReadFile("B1.txt");
            poly2.ReadFile("B2.txt");
            break;
        
        case 2:
            printf("poly1:\t");
            poly1.ShowPoly();
            printf("poly2:\t");
            poly2.ShowPoly();
            printf("add:\t");
            add_result.ShowPoly();
            printf("mult:\t");
            mult_result.ShowPoly();
            break;
        
        case 3: 
            add_result = poly1.Add(poly2);
            break;
        
        case 4:
            polynomial t;
            printf("輸入 t.coef 和 t.expon = ");
            scanf("%d %d", &t.coef, &t.expon);
            poly1.SingleMult(t);
            break;
        
        case 5:
            printf("poly1:\t");
            poly1.Lead_Exp();
            printf("poly2:\t");
            poly2.Lead_Exp();
            printf("add:\t");
            add_result.Lead_Exp();
            printf("mult:\t");
            mult_result.ShowPoly();
            break;

        case 6: {
            int add_coef = 0, add_expon = 0;
            printf("輸入 add_coef 和 add_expon = ");
            scanf("%d %d", &add_coef, &add_expon);
            poly1.Attach(add_coef, add_expon);
            }
            break;

        case 7: {
            int del_expon = 0;
            printf("輸入 del_expon = ");
            scanf("%d", &del_expon);
            poly1.Remove(del_expon);
            }
            break;

        case 8:
            mult_result = poly1.Mult(poly2);
            break;

        default:
            printf("no such command");
            break;
        }
        printf("\n");
    }
    system("pause");
}

void ShowUI() {
    printf("---------------\n");
    printf("1. 讀入多項式\n");
    printf("2. 印出多項式\n");
    printf("3. 多項式相加\n");
    printf("4. 將多項式的係數和項次乘上數值\n");
    printf("5. 印出多項式中最大指數的係數\n");
    printf("6. 增加項式\n");
    printf("7. 刪除多項式中的項式\n");
    printf("8. 多項式相乘\n");
    printf("---------------\n");
}

MyPoly::MyPoly() {
	size = 0;
}

void MyPoly::ReadFile(const char* filename){
    FILE *fptr = NULL;
	size = 0;
    if (fptr = fopen(filename, "r")) {
        while(!feof(fptr))  {
		    fscanf(fptr,"%2d %2d", &terms[size].coef, &terms[size].expon);
		    size++;
	    }
        fclose(fptr);
        printf("%s read file done\n", filename);
    }else {
        printf("no file\n");
    }
}

void MyPoly::ShowPoly() {
	for(int i = 0; i < size; i++) {
		printf("%dx^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("\b\b \n");
}

void MyPoly::SingleMult(polynomial p) {
	for(int i = 0; i < size; i++) {
		terms[i].coef = terms[i].coef * p.coef;
		terms[i].expon = terms[i].expon + p.expon;
	}
    printf("single mult done\n");
}

MyPoly MyPoly::Add(MyPoly B) {
	MyPoly result;
	int a_index = 0, b_index = 0;
	while(a_index < size && b_index < B.size) {
		if(terms[a_index].expon < B.terms[b_index].expon) {
			result.terms[result.size] = B.terms[b_index];
			result.size++;
			b_index++;
		}else if(terms[a_index].expon == B.terms[b_index].expon) {
			int result_coef = terms[a_index].coef + B.terms[b_index].coef;
			
            if(result_coef != 0) {
				result.terms[result.size].coef = result_coef;
				result.terms[result.size].expon = B.terms[b_index].expon;
			}
			result.size++;
			a_index++;
			b_index++;
		}else {
			result.terms[result.size] = terms[a_index];
			result.size++;
			a_index++;
		}
	}
	for(;a_index < size; a_index++) {
		result.terms[result.size] = terms[a_index];
		result.size++;
	}
	for(;b_index < size; b_index++) {
		result.terms[result.size] = B.terms[b_index];
		result.size++;
	}
    printf("add done\n");
	return result;
}

int MyPoly::Lead_Exp() {
	return terms[0].expon;
}

void MyPoly::Attach(int coef, int expon) {
	for(int i = 0; i < size; i++) {
		if(expon > terms[i].expon) {
			for(int j = size; j > i; j--) {
				terms[j] = terms[j-1];
			}
			terms[i].coef = coef;
			terms[i].expon = expon;
			size++;
			break;
		}else if(expon == terms[i].expon) {
			terms[i].coef += coef;
			break;
		}
	}
    printf("attach done\n");
}

void MyPoly::Remove(int num) {
	int index = 0;
	for(int i = 0; i < size; i++) {
		if(terms[i].expon == num) {
			index = i;
			break;
		}
	}
	for(int i = index; i < size; i++) {
		terms[i] = terms[i + 1];
	}
	size--;
	printf("remove done\n");
}

MyPoly MyPoly::Mult(MyPoly B) {
    MyPoly result;
    int index = 0;
    result.size = size * B.size;
    for(int i = 0; i < size ; i++) {
        for(int j = 0; j < B.size; j++){
            result.terms[index].coef = terms[i].coef * B.terms[j].coef;
            result.terms[index].expon = terms[i].expon + B.terms[j].expon;
            index++;
        }
    }
    for (int i = 0; i < result.size; i++) {
        for (int j = 0; j < result.size; j++) {
            if (result.terms[j].expon < result.terms[i].expon) {
                int expon_temp = result.terms[j].expon;
                result.terms[j].expon = result.terms[i].expon;
                result.terms[i].expon = expon_temp;
                int coef_temp = result.terms[j].coef;
                result.terms[j].coef = result.terms[i].coef;
                result.terms[i].coef = coef_temp;
            }
        }
    }
    printf("mult done\n");
    return result;
}
