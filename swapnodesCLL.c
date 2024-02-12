#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head=NULL;
struct node*current;
struct node*insert(int data){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=data;
    
    if(head==NULL){
        head=current=newnode;
        current->next=current;
    }
    else{
        current->next=newnode;
        newnode->next=head;
        current=newnode;
    }
    //return newnode;
}
void swap(int p1,int p2){
    int temp;
    struct node*t1=head,*t2=head;
    int i=0,j=0;
    if(head==NULL){
        printf("Nothing to swap\n");
    }
    else{
        while(i++<p1){
            t1=t1->next;
        }
        while(j++<p2){
            t2=t2->next;
        }
        temp=t1->data;
        t1->data=t2->data;
        t2->data=temp;
    }
}
void display(){
    struct node*curr=head;
    while(curr->next!=head){
        printf("%d->",curr->data);
        curr=curr->next;
    }
    printf("%d\n",curr->data);
}
void main(){
    int ch,data,pos1,pos2;
    while(true){
        printf("1.Insert\n2.Swap\n3.Display\n4.Exit\nEnter Choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter data:");
                    scanf("%d",&data);
                    insert(data);
                    break;
            case 2: printf("Enter positions:");
                    scanf("%d %d",&pos1,&pos2);
                    swap(pos1,pos2);
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
            default:printf("Invalid Option\n");        
        }
    }
}