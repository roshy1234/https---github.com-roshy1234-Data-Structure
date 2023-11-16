#include <stdio.h>

void isempty();
void isfull();
void dequeue();
void enqueue();
void show();

#define SIZE 5
int F = -1;
int R = -1;
int cq[10];


void main() {
    while(1) {
        printf("\n1.isempty()\n2.isfull()\n3.dequeue()\n4.enqueue()\n5.Show()\n6.Exit\n");
        int c;
        printf("Enter the choice:");
        scanf("%d", &c);
        switch (c) {
            case 1:
            isempty();
            break;
            case 2:
            isfull();
            break;
            case 3:
            dequeue();
            break;
            case 4:
            enqueue();
            break;
            case 5:
            show();
            break;
            default : exit(0);    
        }
    }
}


void isempty() {
    if(F==-1) printf("The cicular queue is empty\n");
    else printf("The circular queue is not empty\n");
}

void isfull() {
    if(F==(R+1)%SIZE) printf("The cicular queue is full\n");
    else printf("The circular queue is not full\n");
}

void enqueue() {
    int x;
    scanf("%d",&x);
    if((F == (R + 1) % SIZE)) {
        printf("\nOverflow error\n");
    }
    else if (F==-1 && R==-1) {
        printf("Ente the element to add to circular queue:");
        R=0;
        F=0;
        cq[R]=x;
    }
    else {
        printf("Ente the element to add to circular queue:");
        R=(R+1)%SIZE;
        cq[R] = x;
    }
}

void dequeue() {
    if(F==-1 && R==-1) {
        printf("\nUnderflow error\n");
        return -1;
    }
    else if(R==F) {
        int y = cq[F];
        F=-1;
        R=-1;
        printf("The dequeued element is %d",y);
    }
    else {
        int x = cq[F];
        F=(F+1)%SIZE;
        printf("The dequeued element is %d",x);
    }
}

void show() {
    if(F==-1 && R==-1) printf("Queue is empty");
    int i = F;
    while(i!=R) {
        printf("%d ",cq[i]);
        i = (i+1)%SIZE;
    }
    printf("%d",cq[R]);
}

