#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff,exp;
    struct node *next;
};
struct node *Phead,*Qhead,*Rhead;

struct node *ReadPoly() {
    struct node *new,*ptr,*head=NULL;
    int n;
    printf("\nEnter the number of terms in the polynomial : ");
    scanf("%d",&n);
    printf("\nEnter the coefficients and exponents of the polynomial : ");
    for(int i=1;i<=n;i++) {
        printf("\nEnter coeff%d and exp%d : ",i,i);
        new = malloc(sizeof(struct node));
        scanf("%d",&new->coeff);
        scanf("%d",&new->exp);
        new->next = NULL;
        if(head == NULL) {
            head = new;
            ptr = head;
        }
        else {
            ptr->next = new;
            ptr = new;
        }
    }
    return head;
}

void DisplayPoly(struct node *head) {
    struct  node *ptr;
    if(head == NULL) 
        printf("The polynomial is empty");
    else {
        ptr = head;
        while(ptr->next != NULL) {
            printf("%dx^%d + ",ptr->coeff,ptr->exp);
            ptr = ptr->next;
        }
        printf("%dx^%d",ptr->coeff,ptr->exp);
    }
}

struct node *MulPoly() {
    struct node *new,*P,*Q,*R,*prev,*head = NULL;
    P=Phead;
    Q=Qhead;
    while (P!=NULL) {
        while(Q!=NULL) {
            new = malloc(sizeof(struct node));
            new->exp = P->exp + Q->exp;
            new->coeff = P->coeff*Q->coeff;
            new->next = NULL;
            if(head == NULL) {
                head = new;
                R = head;
            }
            else {
                R->next = new;
                R = new;
            }
            Q = Q->next;
        }
        P = P->next;
        Q = Qhead;
    }
    //to ignore duplicate terms
    P = head;
    while(P!=NULL) {
        prev = P;
        Q = P->next;
        while(Q!=NULL) {
            if(P->exp == Q->exp) {
                P->coeff = P->coeff + Q->coeff;
                prev->next = Q->next;
                free(Q);
                Q = prev->next;
            }
            else {
                prev = Q;
                Q = Q->next;
            }
        }
        P = P->next;
    }
    return head;
}

void main() {
    printf("\nEnter the details of the first polynomial : ");
    Phead = ReadPoly();
    printf("\nEnter the details of the second polynomial : ");
    Qhead = ReadPoly() ;
    Rhead = MulPoly();
    printf("\nFirst Polynomial : ");
    DisplayPoly(Phead);
    printf("\nSecond Polynomial : ");
    DisplayPoly(Qhead);
    printf("\nThe resultant polynomial : ");
    DisplayPoly(Rhead);
    }