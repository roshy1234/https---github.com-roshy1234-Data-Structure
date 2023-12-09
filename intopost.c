#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

char pop();
void push(char x);
int precedence(char symbol);
void intoPost();
int isempty();

char stack[SIZE];
char infix[SIZE] , postfix[SIZE];
int top = -1;

int main() {
   printf("Enter the infix expression:");
   scanf("%s", infix);
   intoPost();
   printf("The postfix expression is:");
   for(int i = 0; i < strlen(postfix); i++)
      printf("%c", postfix[i]);
   return 0;
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
            while((next = pop()) != '(') {
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
   postfix[j++] = '\0';
}


int precedence(char s) {
   if(s=='(') return 3;
   else if(s=='*' || s=='/') return 2;
   else if(s=='+' || s=='-') return 1;
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
   if(top==SIZE-1) {
      printf("Stack is full");
      exit(1);
   }
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
