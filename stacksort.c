#include <stdio.h>
#include <stdlib.h>
#define m 10

int s[m];
int a[m];
int top=-1;

int pop();
void push(int x);

void main() {
    int n;
    printf("Enter the number of elements in the stack:");
    scanf("%d",&n);
    printf("Enter the stack elements:");
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    top = n-1;
    int i = 0;
    while(top!=-1) {
        a[i] = pop();
        i++;
    }
    for(int i=1;i<n;i++) {
        int c = a[i];
        int j = i-1;
        while(j>=0 && a[j]>c) {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = c;
    }
    for(int i=0;i<n;i++) push(a[i]);
    for(int i=top;i>=0;i--) printf("%d\n",s[i]);
}

int pop() {
    if(top == -1) return 0;
    else {
        int x = s[top];
        top--;
        return x;
    }
}

void push(int x) {
    if(top == m-1) printf("Stack is full");
    else {
        top++;
        s[top] = x;
    }
}
