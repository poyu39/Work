#include<stdio.h> 
#include<stdlib.h>

void perm(char [], int, int);
void swap(char*, char*);

int main(){
	char a[5]="abcd";
	perm(a, 0, 3); 
    system("pause");
	return 0;
}

void perm(char a[], int begin, int end){
	int i;
	if(begin == end){
		for(i=0;i<=end;i++){
			printf("%c ", a[i]);
		}
		printf("\n");
	}
	else{
		for(i=begin;i<=end;i++){
			swap(&a[begin], &a[i]);
			perm(a, begin+1, end);
			swap(&a[begin], &a[i]);
		}
	}
}

void swap(char* c1, char* c2){
	char temp;
	temp = *c1;
	*c1 = *c2;
	*c2 = temp;
}