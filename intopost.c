#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX];
char infix[MAX] , postfix[MAX];
int top = -1;

void main() {
    printf("Enter the infix expression:");
    gets(infix);
    intoPost();
}

intoPost() {
    int j=0;
    for(int i=0;i<strlen(infix);i++) {
    char symbol,next;
    switch(symbol) {
        case '(':
                push(symbol);
                break;
        case ')':
                while(next = pop() != ')') {
                    postfix[j++] = next;
                    }
                    break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
                while(!empty() && precedence(stack[top]) >= precedence(symbol)) 
                        postfix[j++] = pop();
                push(symbol); 
                break;
        default :
                    postfix[j++] = symbol;
    }
}
}


int precedence(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
                return 1;
        case '*':
        case '/':
                return 2;
        case '^':
                return 3;
        default:
                return 0;


    }
}