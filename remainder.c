#include <stdio.h>
void main() {
    int m,n,r,c;
    while(1) {
    printf("Enter the choice:");
    scanf("%d",&c);
    if(c==1){    
    printf("Enter the dividend:");
    scanf("%d",&m);
    printf("Enter the divisor:");
    scanf("%d",&m);
    r=m/n;
    printf("The remainder is:%d",r);
    }
    if(c==0) {
        exit();
    }
    }
}