#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;



void error(char *message){
    fprintf(stderr , " %s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head , int value){
    ListNode *p;
    p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    return p;
}

ListNode* insert(ListNode *head,ListNode *pre_Node, int value ){
    ListNode *p;
    p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre_Node->link;
    pre_Node->link = p;
    return head;
}

ListNode* delete_first(ListNode *head){
    ListNode *removed;
    if(head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode *head, ListNode *pre_Node){
    ListNode *removed;
    removed = pre_Node->link;
    pre_Node->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head){
    for(ListNode *p = head; p != NULL; p = p->link)
        printf("%d->",p->data);
    printf("NULL \n");
}




int main(void){
    ListNode *head = NULL;

    for(int i = 0; i<5; i++){
        head = insert_first(head, i);
        print_list(head);
    }
    
    for(int i = 0; i < 5; i++){
        head = delete_first(head);
        print_list(head);
    }
    return 0;
}