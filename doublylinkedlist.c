#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} n;

void display(struct node *head) {
    struct node *temp = head;
    int count = 0;

    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("Number of elements: %d\n", count);
}
void create(n **head){
    printf("Creation of DLL:\n");
    n *nnode;
     n *tail=*head;
    int c = 1;
    while (c != 0) {
        nnode = (n*)malloc(sizeof(n));
        printf("Data:");
        scanf("%d", &nnode->data);
        if (*head == NULL) {
            nnode->prev = NULL;
            *head = nnode;
            nnode->next = NULL;
            tail = nnode;
        } else {
            tail->next = nnode;
            nnode->prev = tail;
            nnode->next = NULL;
            tail =tail->next;
        }
        printf("Wish to Continue(1/0):");
        scanf("%d", &c);
    }
    display(*head);
}
void insert_beg(n **head){
    n *temp=*head;
    n *nnode;
    nnode=(n*)malloc(sizeof(n));
    printf("Enter Data :");
    scanf("%d",&nnode->data);
    temp->prev=nnode;
    nnode->next=temp;
    nnode->prev=NULL;
    *head=nnode;
    display(*head);
}
void insert_end(n **head){
    n *temp=*head;
    while(temp->next!=NULL)
    temp=temp->next;
    n *nnode;
    nnode=(n*)malloc(sizeof(n));
    printf("Enter data:");
    scanf("%d",&nnode->data);
    temp->next=nnode;
    nnode->prev=temp;
    nnode->next=NULL;
    display(*head);
}
void insert_pos(n **head) {
    n *temp = *head, *nnode;
    int pos, c = 1;
    printf("Enter position:");
    scanf("%d", &pos);
    // Create a new node
    nnode = (n*)malloc(sizeof(n));
    printf("Enter Data:");
    scanf("%d", &nnode->data);
    if (pos <= 0) { // Insert at the beginning
        nnode->next = *head;
        nnode->prev = NULL;
        if (*head != NULL)
            (*head)->prev = nnode;
        *head = nnode;
    } else {
        while (temp != NULL && c < pos - 1) {
            temp = temp->next;
            c++;
        }
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        // Insert at the specified position
        nnode->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = nnode;
        temp->next = nnode;
        nnode->prev = temp;
    }
    display(*head);
}

void delete_beg(n **head){
    n *temp=*head;
    temp->next->prev=NULL;
    *head=temp->next;
    free(temp);
    display(*head);
}
void delete_end(n **head){
    n *temp=*head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->prev->next=NULL;
    free(temp);
    display(*head);
}
void delete_pos(n **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    n *temp = *head;
    int l = 0, c = 1, pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    while (temp != NULL) {
        temp = temp->next;
        l++;
    }
    temp = *head;
    if (pos < 1 || pos > l) {
        printf("Specified position is invalid!\n");
        return;
    } else {
        if (pos == 1) {
            *head = temp->next;
            if (*head != NULL)
                (*head)->prev = NULL;
        } else {
            while (c != pos) {
                temp = temp->next;
                c++;
            }
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
        }
        free(temp);
    }
    display(*head);
}
void reverse(n **head) {
    n *temp = *head, *a = *head;
    while (temp != NULL) {
        n *t = temp->next;
        temp->next = temp->prev;
        temp->prev = t;
        temp = temp->prev;  //Important step
    }
    while (a->prev != NULL) //imp loop condition
        a = a->prev;
    n *t = *head;
    *head = a;
    a = t;
    display(*head);
}

int main(){
    n *head = NULL,*tail=NULL;
    create(&head);
    int choice,k=1;
    while(k!=0){
    printf("Enter the option number to be executed -\n1)Insert at beg\n2)Insert at end\n3)Insert at pos\n4)Reverse a DLL\n5)delete at beginning\n6)Delete at End\n7)Delete at Position\nchoice :");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:insert_beg(&head);
        break;
    case 2:insert_end(&head);
    break;    
    case 3:insert_pos(&head);
    break;
    case 4:reverse(&head);
    break;
    case 5:delete_beg(&head);
    break;
    case 6:delete_end(&head);
    break;
    case 7:delete_pos(&head);
    break;
    default:
        break;
    }
    printf("Press '0' to Exit :");
    scanf("%d",&k);
    }
    return 0;
}

