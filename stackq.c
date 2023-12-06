#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 50

int q1[MAX], q2[MAX];
int F1 = -1, R1 = -1, F2 = -1, R2 = -1;

void enqueue(int x, int a[], int *F, int *R) {
    if(*R == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if(*F == -1) {
        *F = 0;
    }
    *R = *R + 1;
    a[*R] = x;
}

int dequeue(int a[], int *F, int *R) {
    int x = -1;
    if(*F == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    x = a[*F];
    if(*F == *R) {
        *F = -1;
        *R = -1;
    } else {
        *F = *F + 1;
    }
    return x;
}

bool isempty(int a[],int F, int R) {
    if(F == -1 || F > R ) return true;
    else return false;
}

void pop() {
    if (isempty(q1,F1,R1)) {
        printf("Stack is Empty\n");
        return;
    }
    while(!isempty(q1,F1,R1)) {
        enqueue(dequeue(q1,&F1,&R1),q2,&F2,&R2);
        if(F1==R1) break;
    }
    if(F1==R1) printf("The popped element is %d\n",dequeue(q1,&F1,&R1));
    while(!isempty(q2,F2,R2)) {
        enqueue(dequeue(q2,&F2,&R2),q1,&F1,&R1);
    }
}

void display(int a[], int F, int R) {
    for(int i=R;i>=F;i--) {
        printf("%d\n",a[i]);
    }
}

void main () {
    int c,d;
    while(1) {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c) {
            case 1: {
                printf("Enter the element to insert:");
                scanf("%d",&d);
                enqueue(d,q1,&F1,&R1);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display(q1,F1,R1);
                break;
            }
            case 4: {
                exit(0);
                break;
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }
}