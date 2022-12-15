#include<stdio.h>
#include<stdlib.h>
#include<math.h> 

#define MAX	80

struct HeapTree {
	int data[MAX];
	int count;
	HeapTree(const char* filename);
    HeapTree();
	void InsertData(int);
	void ShowSpace(int);
	int GetLevel();
	void ShowTree();
    void DelMax();
};

int main() {
	HeapTree t1("a.txt");
	t1.ShowTree();
    
    for(int i = 0; i < 3; i++) {
        t1.DelMax();
        system("pause");
    }
	return 0;
}

HeapTree::HeapTree() {
    count = 0;
    for(int i = 0; i < MAX; i++) {
        data[i] = 0;
    }
}

HeapTree::HeapTree(const char* filename) {
	FILE *fptr = fopen(filename, "r");
	count = 0;
	while(!feof(fptr)) {
		count++;
		fscanf(fptr, "%d", &data[count]);
		InsertData(data[count]); 
        /*
        ShowTree();
		printf("\n");
		system("pause");
        */
	}
	printf("\n");
}

void HeapTree::InsertData(int num) {
	int index = count;
	int temp = 0;
	while(index > 1) {
		if(data[index] > data[index / 2]) {
			temp = data[index / 2];
			data[index / 2] = data[index];
			data[index] = temp;
		}
		index = index / 2;
	}
}

void HeapTree::ShowSpace(int num) {
	for(int i = 0; i < num ; i++) {
		printf(" ");
	}
}

int HeapTree::GetLevel() {
	int level = 0;
	int i = count;
	while(i) {
		level++;
		i = i / 2;
	}
	return level;
}

void HeapTree::ShowTree() {
	int level = 1;
	int height = GetLevel();
	printf("count:%d\n", count);
	printf("height:%d\n", height);
	for(int i = 1; i <= count; i++) {
		ShowSpace(pow(2, height - level + 1));
		printf("\b\b%2d", data[i]);
		ShowSpace(pow(2, height - level + 1));
		
		if(i == pow(2, level) - 1) {
			level++;
			printf("\n");
		}	
	}
    printf("\n");
}

void HeapTree::DelMax() {
    HeapTree copyTree;
    for(int i = 2; i <= count; i++) {
        copyTree.count++;
        copyTree.data[i - 1] = data[i];
        copyTree.InsertData(copyTree.data[count]);
    }
    data[count] = 0;
    count--;
    for(int i = 1; i <= count; i++) {
        data[i] = copyTree.data[i];
    }
    ShowTree();
}