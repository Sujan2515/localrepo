#include <stdio.h>
#include <stdlib.h>

#define BASE 10 

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int getDigit(int number, int place) {
    return (number / place) % BASE;
}

int getMax(Node* head) {
    int max = head->data;
    Node* temp = head->next;
    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

void radixSort(Node** head) {
    Node* buckets[BASE];
    int max = getMax(*head);
    int place;

    for (place = 1; max / place > 0; place *= BASE) {
        for (int i = 0; i < BASE; i++) {
            buckets[i] = NULL;
        }

        Node* temp = *head;
        while (temp != NULL) {
            int digit = getDigit(temp->data, place);
            appendNode(&buckets[digit], temp->data);
            temp = temp->next;
        }

        *head = NULL;
        for (int i = 0; i < BASE; i++) {
            if (buckets[i] != NULL) {
                if (*head == NULL) {
                    *head = buckets[i];
                } else {
                    Node* temp = *head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = buckets[i];
                }
            }
        }
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        appendNode(&head, data);
    }

    printf("Original list: ");
    printList(head);

    radixSort(&head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}
