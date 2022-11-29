#include <stdio.h>
#include <stdlib.h>

int main() {
    int data;
    char letter;
    int num;
    scanf("%d\n", &data);
    
    for(int i = 1; i <= data; i++) {
        printf("Case %d: ", i);
        while(true) {        	
        	letter = getchar();
        	if(letter == '\n') {
        		break;
			} 
            if(letter == EOF) {
                return 0;
            }
            scanf("%d", &num);
            for(int j = 0; j < num; j++) {
                printf("%c", letter);
            }
        }
        printf("\n");
    }
    //system("pause");
    return 0;
}