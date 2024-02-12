#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int pop();
void push(int x);
int eval();

int top=-1;
int stack[SIZE];
char postfix[SIZE];

void main() {
    printf("Enter the postfix expression:");
    scanf("%s",postfix);
    printf("The result of evaluation is %d",eval());
}

int eval() {
    int x,y,i=0;
    char ch;
    while((ch=postfix[i++])!='\0'){
        switch(ch) {
            case '+':
                x = pop();
                y = pop();
                push((y + x));
                break;
            case '-':
                x = pop();
                y = pop();
                push((y - x));
                break;
            case '*':
                x = pop();
                y = pop();
                push((y * x));
                break;
            case '/':
                x = pop();
                y = pop();
                push((y / x));
                break;
            case '^':
                x = pop();
                y = pop();
                push((y ^ x));
                break;
            default:
                push(ch-'0');
        }
    }
    return pop();
}

int pop() {
    if(top==-1)
        return '\0';
    else {
        int a = stack[top];
        top--;
        return a;
    }
}

void push(int x) {
    if(top==SIZE-1)
        printf("Stack is full");
    else {
        stack[++top]=x;
    }
}
