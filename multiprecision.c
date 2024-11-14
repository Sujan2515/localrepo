#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct node {
    int digit;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(int digit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtHead(Node** head, int digit) {
    Node* newNode = createNode(digit);
    newNode->next = *head;
    *head = newNode;
}

// Function to reverse a linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to add two linked lists representing large integers
Node* addLargeIntegers(Node* head1, Node* head2) {
    Node* result = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0) {
        int sum = carry;

        if (head1 != NULL) {
            sum += head1->digit;
            head1 = head1->next;
        }
        
        if (head2 != NULL) {
            sum += head2->digit;
            head2 = head2->next;
        }
        
        carry = sum / 10;
        sum = sum % 10;

        insertAtHead(&result, sum);
    }

    return result;
}

// Function to display the linked list
void displayList(Node* head) {
    while (head != NULL) {
        printf("%d", head->digit);
        head = head->next;
    }
    printf("\n");
}

// Function to convert a string to a linked list
Node* stringToList(char* num) {
    Node* head = NULL;
    int length = strlen(num);

    for (int i = 0; i < length; i++) {
        insertAtHead(&head, num[i] - '0');
    }

    return head;
}

int main() {
    char num1[1000], num2[1000];

    printf("Enter the first large number: ");
    scanf("%s", num1);
    
    printf("Enter the second large number: ");
    scanf("%s", num2);

    // Convert strings to linked lists
    Node* head1 = stringToList(num1);
    Node* head2 = stringToList(num2);

    // Add the two large integers
    Node* result = addLargeIntegers(head1, head2);

    // Display the result
    printf("The sum is: ");
    displayList(result);

    return 0;
}