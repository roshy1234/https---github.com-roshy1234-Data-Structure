#include <stdio.h>
#include <stdlib.h>

void irear();
void drear();
void ifront();
void dfront();
void traverse();
void search();
void imid();
void dmid();

struct node {
   int data;
   struct node *next;
   };
   
struct node *newnode,*head,*tail,*temp,*t;

void main() {
    head = NULL;
    tail = NULL;
    int c;
    while(1){
       printf("\n1.insertionrear\n2.deletionrear\n3.insertionfront\n4.deletionfront\n5.insertionmid\n6.deletionmid\n7.traverse\n8.search\n9,Exit\n");
       printf("Enter choice:");
       scanf("%d",&c);
       switch(c) {
          case 1:
            irear();
            break;
          case 2:
            drear();
            break;
          case 3:
            ifront();
            break;
          case 4:
            dfront();
            break;
          case 5:
            imid();
            break;
          case 6:
            dmid();
            break;
          case 7:
            traverse();
            break;
          case 8:
            search();
            break;
          case 9:
            exit(0);
            break;
          default:
            printf("Invalid choice");
          }
         }
        }
        
void irear() {
    int x;
    printf("Enter element to insert:");
    scanf("%d",&x);
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL) {
       newnode->next=newnode;
       tail=newnode;
       head=newnode;
       }
    else {
       t=head;
       do {
          if(t==tail) {
             tail->next=newnode;
             newnode->next=head;
             tail=newnode;
             }
          t=t->next;
         }
       while(t != head);
        }
       }
      
void drear() {
   if(head==NULL)
       printf("List is empty");
   else if(head == tail) {
       printf("The deleted element is %d",head->data);
       temp = head;
       free(temp);
       head = NULL;
       tail = NULL;
       }
   else {
       t=head;
       do {
          if(t->next==tail) {
             printf("The deleted element is %d",tail->data);
             free(tail);
             tail=t;
             tail->next=head;
             }
             t=t->next;
            }
       while(t!=head);
           }
          }
           
void ifront() {
    int x;
    printf("Enter element to insert:");
    scanf("%d",&x);
    newnode=malloc(sizeof(struct node)); 
    newnode->data=x;
    if(head==NULL) {
       newnode->next=newnode;
       head=newnode;
       tail=newnode;
       }
    else {   
       newnode->next=head;
       head=newnode;
       tail->next = head;
       }
      }
 
void dfront() {
    if(head==NULL) 
       printf("queue is empty");
    else if(head==tail) {
       printf("The deleted element is %d",head->data);
       temp = head;
       free(temp);
       head=NULL;
       tail=NULL;
       }
    else {
       printf("The deleted element is %d",head->data);
       temp=head;
       head=head->next;
       tail->next = head;
       free(temp);
      }
     }
     
void traverse() {
    if(head == NULL && tail==NULL) printf("NULL");
    else {
      t=head;
      do {
         printf("%d ",t->data);
         t=t->next;
          }
      while(t != head);
      }
     }
    
void imid() {
    int pos;
    printf("Enter the position to insert:");
    scanf("%d",&pos);
    int x;
    printf("Enter element to insert:");
    scanf("%d",&x);
    newnode=malloc(sizeof(struct node));
    newnode->data = x;
    if(head == NULL) {
       head = newnode;
       tail = newnode;
       newnode->next = newnode;
       }
    else {
       t=head;
       for(int i=1;i<pos;i++) {
          if(t->next != tail) {
             t = t->next;
             }
          }
       newnode->next = t->next;
       t->next = newnode;
       }
    }
    
void dmid() {
    int pos;
    printf("Enter the position to delete:");
    scanf("%d",&pos);
    temp=head;
    for(int i=1;i<pos;i++) {
       temp = temp->next;
       }
    t=head;
    for(int i=1;i<pos-1;i++) {
       t = t->next;
       }
    t->next = temp->next;
    if(temp == tail) {
       tail = t;
       }
    if(temp == head) {
       head = head->next;
       }
    free(temp);
    }
    
    
       
    
          
