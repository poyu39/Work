#include <stdio.h>
#include <stdlib.h>

int main(){
	int value;
    scanf("%d", &value);
    if(value % 4 == 0 && value % 100 != 0){
		printf("閏年");
	}else if(value % 400 == 0){
		printf("閏年");
	}else{
		printf("非閏年");
	}
}