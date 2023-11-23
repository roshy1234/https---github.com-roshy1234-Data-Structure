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
struct node *newnode,*top,*temp;


void main() {
    top = NULL;
    int c;
    while(1) {
        printf("\n1.push()\n2.pop()\n3.display\n4.peek()\n5.Exit\n");
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
                printf("%d",top->data);
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
    int x;
    printf("Enter the number to push:");
    scanf("%d",&x);
    newnode=malloc(sizeof(struct node));
    newnode->next=top;
    newnode->data=x;
    top=newnode;
    }

void pop() {
    if(top==NULL) {
        printf("Stack is empty");
    }
    else {
        temp=top;
        top=top->next;
        free(temp);
    }
}

void display() {
    if(top == NULL) printf("Stack is empty");
    else {
        temp=top;
        while(temp!=NULL) {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}

