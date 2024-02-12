#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define max 20
char stack[max];
int top=-1;

void push(char c){
    if(top==max-1){
        printf("Stack Overflow\n");
    }
    else{
        stack[++top]=c;
    }
}

char pop(){
    if(top==-1){
        printf("Stack Empty\n");
    }
    else{
        return stack[top--];
        
    }
}

bool similar(char c1,char c2){
    if(c1=='('&&c2==')'){
        return true;
    }
    else if(c1=='{'&&c2=='}'){
        return true;
    }
    else if(c1=='['&&c2==']'){
        return true;
    }
    else{
        return false;
    }
}

int isBalanced(){
    for(int i=0;i<strlen(stack);i++){
        if(stack[i]=='('||stack[i]=='{'||stack[i]=='['){
            push(stack[i]);
        }
        else if(stack[i]==')'||stack[i]=='}'||stack[i]==']'){
            if(top==-1||!similar(pop(),stack[i])){
                return 0;
            }
        }
    }
    if(top!=-1){
        return 0;
    }
    return 1;
}
int main(){
    int chk;
    printf("Enter Expression:");
    scanf("%s",stack);
    chk=isBalanced();
    if(chk==0){
        printf("Not Balanced\n");
    }
    else{
        printf("Balanced\n");
    }
}