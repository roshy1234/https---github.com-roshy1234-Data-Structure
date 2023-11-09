#include <stdio.h> 
void main() {
    int a[10]={5,7,3,4,5,4,3},f=0;
    for(int i=0;i<7;i++){
        int count=0;
        for(int j=0;j<7;j++){
            if(a[i]==a[j]){
                count=count+1;
            }
        }
        printf("Number of element %d is %d\n",a[i],count);
    }
}