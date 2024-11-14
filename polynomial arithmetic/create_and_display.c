#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    float coeff;
    int expo;
    struct node* next;
}poly;


poly *insert(poly*head,float co,int ex){
    poly* temp;
    poly* nnode=(poly*)malloc(sizeof(poly));
    nnode->coeff=co;
    nnode->expo=ex;
    nnode->next=NULL;

    if(head == NULL || ex > head->expo){
        nnode->next=head;
        head=nnode;
    }

    else{
        temp=head;
        while(temp->next != NULL && temp->next->expo > ex){
            temp=temp->next;
            }
        nnode->next=temp->next;
        temp->next=nnode;    
    }
    return head;
}

poly* create(poly*head){
    int n, expo;
    printf("Enter number of terms: ");
    scanf("%d",&n);
    float coeff;
    for(int i=0;i<n;i++){
        printf("Enter the coefficient of term%d: ",i+1);
        scanf("%f",&coeff);
        printf("Enter the exponent of term%d: ",i+1);
        scanf("%d",&expo);
        head=insert(head,coeff,expo);
    }
    return head;
}

void display(poly* head){
    if(head == NULL){
       printf("No polynomial.");
    } 
    else{
        poly* temp=head;
        while(temp != NULL){
            printf("(%.1fx^%d)",temp->coeff,temp->expo);
            temp=temp->next;
            if(temp!=NULL){
                printf("+");
            }
            else {
                printf("\n");
            }
        }
    }
}
int main(){
    poly* head=NULL;
    printf("Enter the polynomial: \n");
    head = create(head);
    display(head);
    return 0;
}



