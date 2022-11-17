#include<stdio.h>
#include<stdlib.h>

struct listNode {
	int data;
	listNode *link;
};


listNode *Add(listNode *head, int num);
listNode *Delete(listNode *head, int deletePosition);
listNode *Insert(listNode *head, int insertNumber, int insertPostition);
void *Edit(listNode *head, int editNumber, int editPosition);
listNode *Inverse(listNode *head);
int Length(listNode *head);
listNode *Combine(listNode *head, listNode *head2);
void Show(listNode *head);

int main(){
	listNode *head = NULL;
	head = Add(head,0);
	//printf("%p\n",head);
	head = Add(head,1);
	head = Add(head,2);
	head = Add(head,3);
    head = Delete(head, 2);
	Show(head);
	
    system("pause");
	return 0;
} 

//新增，在鏈結串列的後面新增一筆資料x。
//傳入值為head以及欲新增的資料；回傳值為head。
listNode *Add(listNode *head, int num) {
	listNode *ptr = head;
	listNode *tmp = (listNode*)malloc(sizeof(listNode));
	tmp->data = num;
	tmp->link = NULL;
	
	if(head == NULL) {
		head = tmp;
		//printf("subroutine head:%p\n",head);
	}else{
		//找到最後一個節點
		
		while(ptr->link != NULL) {
			ptr = ptr->link;
		}
		ptr->link = tmp;
	}
	return head;
} 

//將一筆特定位置的資料刪除。
//傳入值為head以及欲刪除的位置；回傳值為head。
listNode *Delete(listNode *head, int deletePosition) {
	listNode *current = head;
    listNode *pre;

    for(int i = 0; i < deletePosition; i++) {
        pre = current->link;
        current = current->link;
    }
    pre->link = current->link;

    return head;
} 

//將一筆資料插入於特定的位置
//傳入值為1. head 2. 插入的數字 3. 欲插入的位置；回傳值為head。
listNode *Insert(listNode *head, int insertNumber, int insertPostition) {

}

//修改資料，傳入值為1. head 2. 修改的數字 3. 欲修改的位置。   
void *Edit(listNode *head, int editNumber, int editPosition) {

}

//將目前的鏈結串列反轉，傳入值為目前鏈結串列的head，回傳值則為反轉後鏈結串列的head。
listNode *Inverse(listNode *head) {

} 

//計算此鏈結串列的長度，傳入值為head，回傳值為串列長度。  
int Length(listNode *head) {

} 

//將目前的鏈結串列 (head) 與鏈結串列 (head2) 合併，並且將結果存到目前串列，回傳值為head。
listNode *Combine(listNode *head, listNode *head2) {

} 

//顯示串列內容： 1->2->3->Null
void Show(listNode *head) {
	while(head != NULL) {
		printf("%2d->", head->data);
		head = head->link;		
	}
	printf("\b\b  \n");

}