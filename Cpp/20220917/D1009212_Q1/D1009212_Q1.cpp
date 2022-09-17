#include<stdio.h>
#include<stdlib.h>

int main(){
    int MAX_SIZE;
    int i, j, output;
    // scanf("%d", &MAX_SIZE);
    MAX_SIZE = 25;
    int *dyn_arr = (int *)malloc(MAX_SIZE * sizeof(int));
    dyn_arr[0] = 0;
    for(i = 0; i < MAX_SIZE; i++){
        if(i % 5 == 0){
            printf("\n");
        }
        output = rand() % 100 +100;
        do{
            output = rand() % 100 +100;
            for(j = 0; j < i; j++){
                if(output == dyn_arr[j]){
                    break;
                }
            }
        }while(j != i);
        dyn_arr[i] = output;
        printf("%4d", dyn_arr[i]);
    }
    system("pause");
    return 0;
}