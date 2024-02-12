#include<stdio.h>
#include<stdlib.h>
#define max 2
int stack[max];
int top=-1;

void push(int data){
    if(top==max-1){
        printf("Stack overflow\n");
    }
    else{
        stack[++top]=data;
    }
}

int pop(){
    if(top==-1){
        printf("Nothing to pop\n");
        return -1;
    }
    else{
        return stack[top--];
    }
}
int LCM(int a,int b){ 
    int temp; 
    if(a<b){ 
        temp=a;
        a=b; 
        b=temp;
    }
    while(a!=0){ 
        temp=a; 
        a=b%a;
        b=temp; 
    } 
    return b; 
}

void main(){
    int data1,data2,lcm;
    printf("Enter Datas to find LCM of:");
    scanf("%d %d",&data1,&data2);
    lcm=LCM(data1,data2);
    push(lcm);
    printf("LCM of numbers:%d",(data1*data2)/pop());
    
}