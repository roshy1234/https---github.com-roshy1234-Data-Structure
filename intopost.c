#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

char pop();
int precedence(char symbol);
void intoPost();
void push(char x);
int isempty();

char stack[SIZE];
char infix[SIZE] , postfix[SIZE];
int top = -1;

void main() {
   printf("Enter the infix expression:");
   scanf("%s",&infix);
   intoPost();
   printf("The postfix expression is:");
   printf("%s",postfix);
}

void intoPost() {
   int j=0;
   for(int i=0;i<strlen(infix);i++) {
      char symbol,next;
      symbol=infix[i];
      switch(symbol) {
         case '(':
            push(symbol);
            break;
         case ')':
            while(next = pop() != '(') {
            postfix[j++] = next;
            }
            break;
         case '+':
         case '-':
         case '*':
         case '/':
         case '^':
            while(isempty()!=1 && precedence(stack[top]) >= precedence(symbol)) 
               postfix[j++] = pop();
            push(symbol); 
            break;
         default :
            postfix[j++] = symbol;
      }
   }
   while(isempty()!=1) {
      postfix[j++] = pop();
   }
   postfix[j] = '\0';
}


int precedence(char symbol) {
   switch(symbol) {
      case '+':
      case '-':
         return 1;
         break;
      case '*':
      case '/':
         return 2;
         break;
      case '^':
         return 3;
         break;
      default:
         return 0;
   }
}

char pop() {
   if(top==-1)
      return '\0';
   else {
      char a = stack[top];
      top--;
      return a;
   }
}

void push(char x) {
   if(top==SIZE-1)
      printf("Stack is full");
   else {
      top++;
      stack[top]=x;
   }
}

int isempty() {
   if (top == -1)
      return 1;
   else 
      return 0;
}