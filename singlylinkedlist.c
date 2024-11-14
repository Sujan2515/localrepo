#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}n;

void create(struct node**head){
    int p;
    printf("enter size: ");
    scanf("%d",&p);
    printf("enter data: ");
    struct node* temp=*head;
    for(int i=0; i<p; i++){
        struct node* nnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&(nnode->data));
        if(*head==NULL){
            *head=nnode;
            temp=*head;
            nnode->next=NULL;
        }
        else {
            temp->next=nnode;
            nnode->next=NULL;
            temp=temp->next;
        }
    }
}

void display(struct node *head) {
    struct node *temp = head;
    int count = 0;

    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\t");
    printf("Number of elements: %d\n", count);
}

void insertBeg(struct node**head){
   n* nnode=(n*)malloc(sizeof(n));
    printf("enter data: ");
    scanf("%d",&nnode->data);
    nnode->next=*head;
    *head=nnode;
}

void insertEnd(struct node**head){
    n* nnode=(n*)malloc(sizeof(n));
    n*temp=*head;
    printf("enter data: ");
    scanf("%d",&nnode->data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=nnode;
    nnode->next=NULL;
}

void insertAtPos(struct node**head){
    n* nnode=(n*)malloc(sizeof(n));
    n*temp=*head;
    printf("enter data: ");
    scanf("%d",&nnode->data);
    int count=1;
    int pos;
    printf("POSITION: ");
    scanf("%d",&pos);
    if(pos==1){
        nnode->next=*head;
        *head=nnode;
    }
    else {while(count<pos-1){
        temp=temp->next;
        count++;
    }
    nnode->next=temp->next;
    temp->next=nnode;
    }
}

void deleteBeg(struct node**head){
    n*temp=*head;
    *head=temp->next;
    free(temp);
}

void deleteEnd(struct node**head){
    n*temp=*head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void deleteAtPos(struct node**head){
    n*temp=*head;
    int pos,count=1;
    printf("POSITION: ");
    scanf("%d",&pos);
    if(pos==1){
        *head=temp->next;
    }
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    temp->next=temp->next->next;
}

void reverse(struct node** head){
    n* temp1=*head,*temp2;
    n* temp3=NULL;
    while(temp1!=NULL){
        temp2=temp1->next;
        temp1->next=temp3;
        temp3=temp1;
        temp1=temp2;
    }
    *head=temp3;
}

void bubbleSort(n** head){
    n*temp1;
    n*temp2=NULL;
    for(temp1=*head;temp1!=NULL;temp1=temp1->next){
        for(temp2=*head;temp2->next!=NULL;temp2=temp2->next){
            if(temp2->data>temp2->next->data){
                int t=temp2->data;
                temp2->data=temp2->next->data;
                temp2->next->data=t;
            }
        }
    }

}

int main(){
    n* head=NULL;
    create(&head);
    display(head);
    int choice;
    printf("Enter choice:\n1)Insert at beg\n2)Insert at end\n3)Insert at pos\n4)Delete at beg\n5)Delete at end\n6)Delete at pos\n7)Display LL\n8)Reverse\n9)Bubble sort\nChoice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: insertBeg(&head);
        display(head);
        break;
        
        case 2: insertEnd(&head);
        display(head);
        break;
        
        case 3: insertAtPos(&head);
        display(head);
        break;
        
        case 4: deleteBeg(&head);
        display(head);
        break;
        
        case 5: deleteEnd(&head);
        display(head);
        break;
        
        case 6: deleteAtPos(&head);
        display(head);
        break;
        
        case 7: display(head);
        break;
       
       case 8: reverse(&head);
        display(head);
        break;
        
        case 9: bubbleSort(&head);
        display(head);
        break;
        default:printf("Enter valid input");
    }
    return 0;
}

