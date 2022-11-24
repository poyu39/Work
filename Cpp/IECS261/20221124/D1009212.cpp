#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 12

struct node {
    int data;
    node* link;
};

struct equivalence {
    node* seq[MAX_SIZE];
    void eqRead(char*);
    void add(int, int);
    void ShowList();
    void ShowClass();
    equivalence() {
        for (int i = 0; i < MAX_SIZE; i++) {
            seq[i] = NULL;
        }
    }
};

struct stack {
    
};


int main() {
    equivalence MyEq;
    MyEq.eqRead("1.txt");
    MyEq.ShowList();
    system("pause");
    return 0;
}

void equivalence::eqRead(char* filename) {
    int a, b;
    FILE* fptr = fopen(filename, "r");
    while (!feof(fptr)) {
        fscanf(fptr, "%d %d", &a, &b);
        add(a, b);
    }
}

void equivalence::add(int a, int b) {
    node* temp = (node*)malloc(sizeof(node));
    temp->link = seq[a];
    temp->data = b;
    seq[a] = temp;

    temp = (node*)malloc(sizeof(node));
    temp->link = seq[b];
    temp->data = a;
    seq[b] = temp;
}

void equivalence::ShowList() {
    node* ptr = NULL;
    for(int i = 0; i < MAX_SIZE; i++) {
        printf("seq[%d]->", i);
        ptr = seq[i];
        while(ptr != NULL) {
            printf("%d->", ptr->data);
            ptr = ptr->link;
        }
        printf("\b\b  \n");
    }
}

void equivalence::ShowClass() {
    
}