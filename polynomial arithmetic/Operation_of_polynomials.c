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
void Addition(poly* head1,poly *head2){
     poly* temp1=head1;
     poly* temp2=head2;
     poly* head3=NULL;
     while(temp1!=NULL && temp2!=NULL){
        if(temp1->expo == temp2->expo){
            head3=insert(head3, temp1->coeff + temp2->coeff, temp1->expo);
            temp1=temp1->next;
            temp2=temp2->next;
     }
     else if(temp1->expo > temp2->expo){
        head3=insert(head3, temp1->coeff, temp1->expo);
        temp1=temp1->next;
     }
     else if(temp1->expo < temp2->expo){
           head3=insert(head3,temp2->coeff,temp2->expo);
           temp2=temp2->next;
     }
}
while(temp1!=NULL){
    head3=insert(head3,temp1->coeff,temp1->expo);
    temp1=temp1->next;
}
while(temp2!=NULL){
    head3=insert(head3,temp2->coeff,temp2->expo);
    temp2=temp2->next;
}
printf("Polynomial added: ");
display(head3);
}

void Multiplication(poly*head1,poly* head2){
    poly*temp1 = head1;
    poly*temp2 = head2;
    poly*head3 = NULL;
    if(head1==NULL || head2==NULL){
        printf("Polynomial is empty\n");
        return;
    }
    while(temp1!=NULL){
        while(temp2!=NULL){
            head3= insert(head3, temp1->coeff*temp2->coeff, temp1->expo+temp2->expo);
            temp2=temp2->next;
        }
        temp1=temp1->next;
        temp2 = head2;
    }
    printf("Before simplification: ");
    display(head3);

    poly* ptr = NULL;
    poly* temp3 = head3;
    while(temp3->next!=NULL){
        if(temp3->expo == temp3->next->expo){
            temp3->coeff = temp3->coeff + temp3->next->coeff;
            ptr = temp3->next;
            temp3->next = temp3->next->next;
            free(ptr);
            ptr = NULL;
        }
        else{
            temp3 = temp3->next;
        }
    }
    printf("After simplification: ");
    display(head3);
}

int main(){
    poly* head1=NULL;
    poly* head2=NULL;
    printf("Enter the first polynomial: \n");
    head1= create(head1);
    printf("Enter the second polynomial: \n");
    head2 = create(head2);
    printf("Select choice: \n1.Addition\n2.Multiplication\n");
    int choice;
    printf("Choice: ");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:Addition(head1,head2);
        break;
        case 2:Multiplication(head1,head2);
        break;
        default: printf("Enter valid choice");
    }
    
    return 0;
}