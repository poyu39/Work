#include <stdio.h>
#include <stdlib.h>

#define MAX 31

int cool(char input[MAX]) {
    int letter[26];
    int cool = 0;
    int len = 0;
    for (int i = 0; i < 26; i++) {
        letter[i] = 0;
    }
    for (int i = 0; input[i] != '\0'; i++) {
        letter[input[i] - 97]++;
        len++;
    }
    // for (int i = 0; i < 26; i++) {
    //     printf("%d ", letter[i]);
    // }
    int count = 0;
    int diff = 0;
    for (int i = 0; i < 26; i++) {
        if (letter[i] != 0) {
            diff++;
            for (int j = i + 1; j < 26; j++) {
                if (letter[i] == letter[j] && letter[i] > 0) {
                    count++;
                }
            }
        }
        
    }
    if (count > 0) {
        return 0;
    } else {
        if (diff > 1) {
            return 1;
        } else {
            return 0;
        }
        
    }
}

int main() {
    int data_count;
    int case_count = 1;
    while (scanf("%d", &data_count) != EOF) {
        getchar();
        int cool_count = 0;
        char input[MAX];
        for (int i = 0; i < data_count; i++) {
            gets(input);
            cool_count += cool(input);
        }
        printf("Case %d: %d\n", case_count, cool_count);
        case_count++;
    }
}