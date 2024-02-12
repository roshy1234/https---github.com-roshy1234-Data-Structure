#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*next;
};
struct node*h1=NULL,*h2=NULL,*h3=NULL;


void insert(struct node **head,int data){
    struct node*newnode=malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        struct node*current=*head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next=newnode;
    }
}

struct node *merge(struct node *a, struct node *b){
    struct node *result=NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    if(a->data<=b->data){
        result=a;
        result->next=merge(a->next,b);
    }
    else{
        result=b;
        result->next=merge(a,b->next);
    }
    return result;
}

void display(struct node*head){
    struct node*curr=head;
    while(curr->next!=NULL){
        printf("%d->",curr->data);
        curr=curr->next;
    }
    printf("%d\n",curr->data);
}



void main() {
    int ch,data;
    while(true){
        printf("\n1.Insert in list 1\n2.Insert in list 2\n3.Merge\n4.Display list 1\n5.Display list 2\n6.Display merge\n7.Exit\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter data:");
                    scanf("%d",&data);
                    insert(&h1,data);
                    break;
            case 2: printf("Enter data:");
                    scanf("%d",&data);
                    insert(&h2,data);
                    break;
            case 3: h3=merge(h1,h2);
                    break;
            case 4: display(h1);
                    break;
            case 5: display(h2);
                    break;
            case 6: display(h3);
                    break;
            case 7: exit(0);
            default:printf("Invalid Choice\n");
        }
    }
}
