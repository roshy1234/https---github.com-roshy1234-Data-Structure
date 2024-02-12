#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node*next;
}*newnode,*head=NULL,*current;

int temp;

void insert(int data){
    newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=data;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node *temp;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    //return head;
}
void sort(){
    if(head==NULL){
        printf("Nothing to sort\n");
    }
    else{
        for(struct node*i=head;i!=NULL;i=i->next){
            for(struct node*j=i->next;j!=NULL;j=j->next){
                if(i->data>j->data){
                    temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
            }
        }    
    }
}
void display(){
    current=head;
    while(current!=NULL){
        printf("%d\t",current->data);
        current=current->next;
    }
printf("\n");
}
void main(){
    int ch,key;
    while(true){
        printf("1.Insert\n2.Sort\n3.Display\n4.Exit\nEnter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter data : ");
                    scanf("%d",&key);
                    insert(key);
                    break;
            case 2:sort();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
            default:printf("Invalid\n");        
            
        }
    }
}