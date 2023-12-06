#include <stdio.h>
#define SIZE 10

void push(int x);
int pop();
int top = -1;
int s[SIZE];

void main() {
    int n;
    printf("Enter the decimal number:");
    scanf("%d",&n);
    while (n != 0) {
        push(n % 2);
        n /= 2;
    } 
    printf("The binary number is:");
    while(top!=-1) {
        printf("%d",pop());
    }
}

int pop() {
    if(top==-1)
        return '\0';
    else {
        int a = s[top];
        top--;
        return a;
    }
}

void push(int x) {
    if(top==SIZE-1)
        printf("Stack is full");
    else {
        top++;
        s[top]=x;
    }
}