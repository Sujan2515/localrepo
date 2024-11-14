#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    int data;
    struct node* next;
}n;

n* create(int data){
    n* nnode = (n*)malloc(sizeof(n));
    nnode->data = data;
    nnode->next = NULL;
    return nnode;
}

void insert(n* head, int newdata){
    n* nnode = create(newdata);
    nnode->next = head;
    head = nnode;
}

void display(n* head){
    n* temp = head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void addlinkedlist(n* first, n* second){
    n* result = NULL;
    n* prev, *temp = NULL;
    int carry = 0;
    int sum;
    while(first != NULL || second != NULL){
       sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
       carry = (sum >= 10) ? 1 : 0;
       sum = sum % 10;
    }
}

