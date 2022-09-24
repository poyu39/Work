#include<stdio.h> 
#include<stdlib.h>
#include<math.h>

int plus(char [], int, int);

int main(){
    int MAX_SIZE;
    scanf("%d", &MAX_SIZE);
    char a[MAX_SIZE] = "";
    for(int i = 0 ; i < MAX_SIZE ; i++){
        a[i] = 0;
    }
    
	plus(a, pow(2, MAX_SIZE), MAX_SIZE); 
    system("pause");
	return 0;
}

int plus(char a[], int count, int MAX_SIZE){
    if(count == 0){
        return 0;
	}
	else{
        int i;
        do{
            for(i = 0 ; i < MAX_SIZE ; i++){
                if(a[i] == 2){
                    a[i - 1] = a[i - 1] + 1;
                    a[i] = 0;
                    break;
                }
            }
        }while(i < MAX_SIZE);

        for(int i = 0 ; i < MAX_SIZE ; i++){
            printf("%d", a[i]);
        }
        printf("\n");
        a[MAX_SIZE - 1] = a[MAX_SIZE - 1] + 1;
        return plus(a, count - 1, MAX_SIZE);
	}
}