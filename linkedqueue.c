#include <stdio.h>
#include <stdlib.h>

void dequeue();
void enqueue();
void display();

struct node {
    int data;
    struct node *next;
};

struct node *front,*rear,*newnode,*temp;


void main() {
    front=NULL;
    rear=NULL;
    int c;
    while(1) {
        printf("\n1.enqueue()\n2.dequeue()\n3.display()\n4.rear\n5.front\n6.Exit\n");
        printf("Enter the choice:");
        scanf("%d",&c);
        switch(c) {
            case 1:
                enqueue();
                break;
            case 2: 
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("The rear element is:%d",rear->data);
                break;
            case 5:
                printf("The front element is:%d",front->data);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice");
            }
        }
        
    }

void enqueue() {
    newnode=malloc(sizeof(struct node));
    int x;
    printf("Enter the data to enqueue:");
    scanf("%d",&x);
    if(front==NULL) {
        front=rear=newnode;
        front->next=NULL;
        rear->next=NULL;
        front->data=x;
        rear->data=x;
    }
    else {
        rear->next=newnode;
        rear=newnode;
        rear->data=x;
        rear->next=NULL;
    }
}

void dequeue() {
    if(front==NULL)
        printf("Queue is empty");
    else if(front==rear) {
        printf("Deleted element is %d",front->data);
        temp=front;
        front=NULL;
        rear=NULL;
        free(temp);
    }
    else {
        printf("Deleted element is %d",front->data);
        temp=front;
        front=front->next;
        free(temp);
    }
}

void display() {
    if(front==NULL) printf("Queue is empty");
    else {
        temp=front;
        while(temp!=NULL) {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}