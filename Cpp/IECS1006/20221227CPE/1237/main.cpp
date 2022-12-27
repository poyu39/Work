#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int D;
        scanf("%d", &D);
        char name[D][100];
        int range[D][2];
        for (int j = 0; j < D; j++) {
            char input_name[100] = {};
            scanf("%s %d %d", &input_name, &range[j][0], &range[j][1]);
            int k;
            for (k = 0; input_name[k] != '\0'; k++) {
                name[j][k] = input_name[k];
            }
            name[j][k]  = '\0';
        }
        
        int Q;
        scanf("%d", &Q);
        for (int j = 0; j < Q; j++) {
            int P;
            scanf("%d", &P);
            int k;
            int output_name;
            int check = 0;
            for (k = 0; k < D; k++) {
                if (P >= range[k][0] && P <= range[k][1]) {
                    check++;
                    output_name = k;
                }
            }
            if (check == 1) {
                printf("%s\n", name[output_name]);
            } else {
                printf("UNDETERMINED\n");
            }
        }
        printf("\n");
    }
    //system("pause");
}