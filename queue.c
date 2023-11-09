#include <stdio.h>
#include <stdlib.h>
#define s 5

int F=-1,R=-1,queue[s];
void enqueue();
void dequeue();
void isempty();
void isfull();
void show();

void main() {
    
    while(1) {
        int choice;
        printf("\n1.To enqueue\n2.To dequeue\n3.To check isempty\n4.To check isfull\n5.Show\n6.End\n");
        printf("Enter the choice of operation:");
        scanf("%d",&choice);

        switch(choice) {
            case 1 : enqueue(); break;
            case 2 : dequeue(); break;
            case 3 : isempty(); break;
            case 4:isfull();break;
            case 5:show();break;
            case 6:exit(0);
            default:printf("Invalid Choice \n");
        }
    }
}

void enqueue() {
    int x;
    if ( R== s-1) printf("Stack overflow\n");
    else if(F==-1) { 
        F=0;
        R=R+1;
        printf("Enter the number to insert:");
        scanf("%d",&x);
        queue[R]=x;
        }
    else {
        R=R+1;
        printf("Enter the number to insert:");
        scanf("%d",&x);
        queue[R]=x;
    }
}

void dequeue() {
    if(F == -1 || F > R ) printf("Underflow");
    else {
        int data;
        F=F+1;
        data = queue[F-1];
        printf("The dequeued element is %d",data);
    }
}

void isempty() {
        if(F == -1 || F > R ) printf("Queue is empty");
        else printf("Queue is not empty");
}

void isfull() {
    if( R == s-1&& F==0) printf("Queue is full");
    else{
        printf("Queue is not full");
    }
}

void show() {
    for(int i=R;i>=F;i--) {
        printf("%d\n",queue[i]);
    }
}

