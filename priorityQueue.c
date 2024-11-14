#include<stdio.h>
#include<stdlib.h>

// Node structure
typedef struct node {
    int data;
    int priority;
    struct node* next;
    struct node* prev;
} n;

struct node* head = NULL;

void createnode(int data, int priority) {
    struct node* nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = data;
    nnode->priority = priority;
    nnode->next = NULL;
    nnode->prev = NULL;

    if (head == NULL) {
        head = nnode;
    } else {
        struct node* temp = head;
        if (nnode->priority < head->priority) {
            nnode->next = head;
            head->prev = nnode;
            head = nnode;
        } else {
            while (temp->next != NULL && temp->next->priority <= nnode->priority) {
                temp = temp->next;
            }
            nnode->next = temp->next;
            nnode->prev = temp;

            if (temp->next != NULL) {
                temp->next->prev = nnode;
            }
            temp->next = nnode;
        }
    }
}

int main() {
    int s, data, prior;
    printf("Enter size: ");
    scanf("%d", &s);
    for (int i = 1; i <= s; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        printf("Enter priority: ");
        scanf("%d", &prior);
        createnode(data, prior);  
    }

    struct node* temp = head;
    printf("\nPriority List:\n");
    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }

    return 0;
}
