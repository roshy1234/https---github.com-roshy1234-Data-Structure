#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct node{
    char data[50];
    struct node*next;
};
struct node*head=NULL;

void insert(char data[]){
    struct node*newnode=malloc(sizeof(struct node));
    struct node*current=head;
    strcpy(newnode->data, data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        while(current->next != NULL){
            current = current->next;
        }
        current->next=newnode;
    }
}

bool isPalindrome(char c[]){
    int start=0,end=strlen(c)-1;
    while(start<end){
        if(c[start++]!=c[end--]){
            return false;
        }
    }
    return true;
}

void display(){
    struct node*curr=head;
    while(curr->next!=NULL){
        if(isPalindrome(curr->data))
            printf("%s->",curr->data);
        curr=curr->next;
        }
        if(isPalindrome(curr->data))
            printf("%s\n",curr->data);
}

void main(){
    int ch;
    char str[50];
    while(true){
        printf("\n1.Insert\n2.Display\n3.exit\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter word:");
                    scanf("%s",str);
                    insert(str);
                    break;
            case 2:display();
                    break;
            case 3:exit(0);
            default:printf("Invalid Choice\n");        
        }
    }
}