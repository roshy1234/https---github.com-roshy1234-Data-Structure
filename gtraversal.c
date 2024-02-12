#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node {
    int data;
    struct node *next;
};

int top=-1,f=0,r=-1;

//function to add last
struct node * addLast(struct node *head,int data){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (head==NULL){
        head=newnode;
    }
    else{
        struct node *current = head;
        while (current->next!= NULL){
            current =  current->next;
        }
        current->next = newnode;
    }
    return head;
}

//stack and queue functions
bool isEmptyS(){
    return (top==-1);
}
bool isEmptyQ(){
    return (f>r);
}
void  push(int v, int S[v],int data){
    S[++top]=data;
}
int  pop(int v,int S[v]){
    top=top-1;
    return S[top+1];
}
int  deQueue(int  v,int Q[v]){
    f=f+1;
    return Q[f-1];
}
void enQueue(int v,int Q[v],int data){
    Q[++r]=data;
}

//main function
void main(){
    int v,data,m;
    printf("Enter number of vertices : ");
    scanf("%d",&v);
    struct node *aList[v];
    //input vertices
    printf("Enter vertices :\n");
    for (int i=0;i<v;i++){
        aList[i]=NULL;
        scanf("%d",&data);
        aList[i]=addLast(aList[i],data);
    }
    for (int i=0;i<v;i++){
        printf("Enter no neighbours of vertex %d\n",aList[i]->data);
        scanf("%d",&m);
        printf("Enter neighbours : \n");
        for (int j=0;j<m;j++){
            scanf("%d",&data);
            aList[i]=addLast(aList[i],data);
        }
    }
    printf("Adjescentsy List :\n");
    for (int i=0;i<v;i++){
        struct node *current = aList[i];
        while(current->next!=NULL){
            printf("%d-->",current->data);
            current=current->next;
        }
        printf("%d\n",current->data);
    }
    int Stack[v],visit[v],Queue[v];
    push(v,Stack,aList[0]->data);
    int index = -1;
    while(!isEmptyS()){
        struct node *current;
        int high = pop(v,Stack);
        visit[++index]=high;
        for (int i=0;i<v;i++){
            if (aList[i]->data==high){
                current = aList[i]->next;
            }
        }
        while(current!=NULL){
            int f=0;
            for (int i=0;i<=index;i++){
                if(visit[i]==current->data){
                    f=1;
                }
            }
            for(int i=0;i<=top;i++){
                if(Stack[i]==current->data){
                    f=1;
                }
            }
            if (f!=1){
                push(v,Stack,current->data);
            }
            current=current->next;
        }
    }

    printf("Depth First Search : \n");
    for (int i = 0;i<=index;i++){
        printf("%d ",visit[i]);
    }
    printf("\n");
    index=-1;
    visit[++index] = aList[0]->data;
    enQueue(v,Queue,aList[0]->data);
    while(!isEmptyQ()){
        struct node *current;
        int low = deQueue(v,Queue);
        for (int i = 0;i<v;i++){
            if (aList[i]->data==low){
                current = aList[i];
            }
        }
        while(current->next!=NULL){
            current=current->next;
            int f=0;
            for (int i = 0 ; i<=index;i++){
                if(visit[i]==current->data){
                    f=1;
                }
            }
            if (f!=1){
                visit[++index]=current->data;
                enQueue(v,Queue,current->data);
            }
        }
    }
    printf("Breadth First Search : \n");
    for(int i =0;i<=index;i++){
        printf("%d ",visit[i]);
    }
    printf("\n");
}