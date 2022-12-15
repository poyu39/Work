#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define MAX 50

struct Node {
	char data;
	Node* llink;
	Node* rlink;
	Node() {
		llink = NULL;
		rlink = NULL;
	}
};

struct Tree {
	Node* root;
	int Height;
	Tree(const char *filename);
	void LevelTraversal();	
};

struct Queue {
	Node* seq[MAX];
	int front, rear;
	Queue() {
		front = 0;
		rear = 0;
	}
	bool IsFull();
	bool IsEmpty();
	void Add(Node*);
	Node* Del(); 
};

void PrnSpace(int);

void Preorder(Node*);
void Inorder(Node*);
void Postorder(Node*);

int main() {
	Tree MyTree("a.txt");
	Node* head = MyTree.root;
	printf("%c\n", head->data);
	printf("%c %c\n", head->llink->data, head->rlink->data);
	printf("%c %c\n", head->llink->llink->data, head->llink->rlink->data);
	MyTree.LevelTraversal();
    printf("\n");
    printf("Preorder: ");
    Preorder(head);
    printf("\n");

    printf("Inorder: ");
    Inorder(head);
    printf("\n");

    printf("Postorder: ");
    Postorder(head);
    printf("\n");
	system("pause");
	return 0;
} 

Tree::Tree(const char *filename) {
	char s[MAX] = {0};
	int i = 0;
	Node *temp = NULL;
	Node *LChild = NULL, *RChild = NULL;
	
	int LvlCount = 1;
	int count = 0;
	
	Queue MyQueue; 
	
	Height = 0;
	
	FILE *fptr = fopen(filename, "r");
	fscanf(fptr,"%s", s);
	printf("%s\n", s);
	if(s[i] != '\0') {
		temp = (Node*)malloc(sizeof(Node));
		temp->data = s[i];
		temp->llink = NULL;
		temp->rlink = NULL;
		root = temp;
		MyQueue.Add(temp);
		i++;
		Height++;
		LvlCount = LvlCount * 2;
	}
	while(!MyQueue.IsEmpty()) {
		temp = MyQueue.Del();
		if(s[i] != '\0') {
			LChild=(Node*)malloc(sizeof(Node));
			LChild->data = s[i];
			LChild->llink = NULL;
			LChild->rlink = NULL;
			 
			temp->llink = LChild;
			i++;
			MyQueue.Add(LChild);
			count++;
		}
		if(s[i]!='\0') {
			RChild = (Node*)malloc(sizeof(Node));
			RChild->data = s[i];
			RChild->llink = NULL;
			RChild->rlink = NULL;
			temp->rlink = RChild;
			
			i++;
			MyQueue.Add(RChild);
			count++;
		} 
		if(count == LvlCount) {
			Height++;
			count = 0;
			LvlCount = LvlCount * 2;
		}
	}			
}

void Tree::LevelTraversal() {
	Queue MyQueue;
	Node *ptr = NULL;
	int LvlCount = 1;
	int count = 0;
	MyQueue.Add(root);
	printf("Tree Height:%d\n", Height);
	int height = Height;
	while(!MyQueue.IsEmpty()) {
		ptr = MyQueue.Del();
		//printf("\nptr:%p\n",ptr);
		if(ptr != NULL) {
			PrnSpace(pow(2, height));
			printf("\b%c", ptr->data);
			PrnSpace(pow(2, height));
		}
		count++;
		if(ptr != NULL) {
			MyQueue.Add(ptr->llink);
			MyQueue.Add(ptr->rlink);
		}
		if(LvlCount == count) {
			printf("\n");
			count = 0;
			LvlCount = LvlCount * 2;
			height--;
		}
	}	
}

bool Queue::IsFull() {
	if((rear + 1) % MAX == front)
		return true;
	else
		return false;
	
}

bool Queue::IsEmpty() {
	if(rear == front)
		return true;
	else
		return false;

} 

void Queue::Add(Node* tmp) {
	if(IsFull()!=true) {
		rear = (rear + 1) % MAX;
		seq[rear]=tmp; 
	} 
}

Node* Queue::Del() {
	Node* tmp = NULL;
	if(IsEmpty() != true) {
		front = (front + 1) % MAX;
		tmp = seq[front];		
	}
	return tmp;
}

void Preorder(Node* ptr) {
    if(!ptr){
        return; 
    }    
    printf("%c ", ptr->data);
    Preorder(ptr->llink);
    Preorder(ptr->rlink);
}

void Inorder(Node* ptr) {
    if(!ptr){
        return; 
    }    
    Inorder(ptr->llink);
    printf("%c ", ptr->data);
    Inorder(ptr->rlink);
}

void Postorder(Node* ptr) {
    if(!ptr){
        return; 
    }    
    Postorder(ptr->llink);
    Postorder(ptr->rlink);
    printf("%c ", ptr->data);
}

void PrnSpace(int count) {
	for(int i = 0; i < count; i++) {
		printf(" ");
	}
}

