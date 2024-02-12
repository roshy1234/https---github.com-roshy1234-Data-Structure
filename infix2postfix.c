#include <stdio.h>
#include <ctype.h>
#define s 50
//global declaration of stack and top
char stack[s];
int top=-1;
//stack operations
void push(char x) {
    stack[++top]=x;
}

int pop() {
    top--;
    return stack[top+1];
}
//precedence function
int pri(char symbol) {
    if(symbol=='^')
        return 3;
    else if(symbol=='*' || symbol=='/')
        return 2;
    else if(symbol=='+' || symbol=='-')
        return 1;
    else
        return 0;
}
// main function
void main() {
    char infix[50],postfix[50],ch,elem;
    int i=0,p=0;
    printf("Enter the infix expression : ");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0') {
        if(ch=='(')
            push(ch);
        else if(isalnum(ch))
            postfix[p++]=ch;
        else if(ch==')') {
            while(stack[top]!='(')
                postfix[p++]=pop();
            elem=pop();
        }
        else {
            while(pri(stack[top])>=pri(ch))
                postfix[p++]=pop();
            push(ch);
        }
    }
    //popping the remaining elements from the stack to the postfix expression
    while(stack[top]!='#')
        postfix[p++]=pop();
    postfix[p]='\0';
    //displaying the postfix expression
    printf("The postfix expression is : %s\n",postfix);
}
