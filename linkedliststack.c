#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
int peek();

struct node {
    int data;
    struct node *next;
};
struct node *head,*newnode,*top,*temp;


void main() {
    head = NULL;
    int c;
    while(1) {
        printf("Enter the choice:");
        scanf("%d",&c);
        switch(c) {
            case 1:
                push();
                break;
            case 2: 
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice");
            }
        }
    }

void push() {
    if(head==NULL) {
        newnode = malloc(sizeof(struct node));
        head=newnode;
        printf("Enter data to push:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        top=newnode;
    }
    else {
        newnode = malloc(sizeof(struct node));
        top->next=newnode;
        printf("Enter data to push:");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        top=newnode;
        }
    }

void pop() {
    if(head==NULL) printf("Stack is empty\n");
    else if(head==top) {
        free(top);
        head=NULL;
    }
    else {
        temp=head;
        while(temp!=NULL) {
            if(temp->next==top) {
                printf("The popped element is %d\n",top->data);
                free(top);
                top=temp;
                top->next=NULL;
                break;
            }
            temp=temp->next;
        }   
    }
}

void display() {
    if(head == NULL) printf("Stack is empty");
    else {
        temp=head;
        while(temp!=NULL) {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

