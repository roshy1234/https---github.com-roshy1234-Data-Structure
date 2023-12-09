#include <stdio.h>
#include <stdlib.h>
#define m 5

int top = -1,s[m];
void push();
void pop();
void isempty();
void isfull();
void show();

void main() {
    
    while(1) {
        int c;
        printf("\n1.To push 2.To pop 3.To check isempty 4.To check isfull 5.Show 6.End\n");
        printf("Enter the choice : ");
        scanf("%d",&c);

        switch(c) {
            case 1 : push(); break;
            case 2 : pop(); break;
            case 3 : isempty(); break;
            case 4 : isfull();break;
            case 5 : show();break;
            case 6 : exit(0);
            default : printf("Invalid Choice \n");
        }
    }
}

void pop() {
    if(top == -1) printf("Underflow");
    else {
        int x = s[top];
        top--;
        printf("The poped element is %d",x);
    }
}

void push() {
    int x;
    printf("Enter the element to push:");
    scanf("%d",&x);
    if(top == m-1) printf("Overflow");
    else {
        top++;
        s[top] = x;
    }
}

void isempty() {
    if(top = -1) printf("Stack is empty");
    else printf("Stack is not empty");
}

void isfull() {
    if(m-1) printf("Stack is full");
    else printf("Stack is not full");
}

void show() {
    for(int i=top;i>=0;i--) {
        printf("%d\n",s[i]);
    }
}