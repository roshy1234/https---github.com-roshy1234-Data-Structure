#include <stdio.h>

struct poly {
    int coeiff;
    int exp;
};
struct poly a[10],b[10],c[10];

void main() {

    

    int d1,d2,d;

    //input polynomial degree

    printf("Enter the degree of polynomial a:");
    scanf("%d",&d1);

    printf("\nEnter the degree of polynomial b:");
    scanf("%d",&d2);

    d=d1>d2?d1:d2;

    int l=0,m=0,n=0;

//inputting coefficients and exponents of polynomial
if(d1>d2 ){
    printf("Enter the coefficients of a:\n");
    for(int i=0;i<=d;i++) {
        printf("The coefficient of x^%d:",i);
        scanf("%d",&a[i].coeiff);
        a[m++].exp=i;
    }

    printf("Enter the coefficients of b:\n");
    for(int i=0;i<=d2;i++) {
        printf("The coefficient of x^%d:",i);
        scanf("%d",&b[i].coeiff);
        b[n++].exp=i;
    }

        for(int i=d2+1;i<=d;i++) {
        b[i].coeiff=0;
        b[n++].exp=i;
    }

}

if(d1<d2) {
        printf("Enter the coefficients of a:\n");
    for(int i=0;i<=d1;i++) {
        printf("The coefficient of x^%d:",i);
        scanf("%d",&a[i].coeiff);
        a[m++].exp=i;
    }

    for(int i=d1+1;i<=d;i++) {
        a[i].coeiff=0;
        a[m++].exp=i;
    }

    printf("Enter the coefficients of b:\n");
    for(int i=0;i<=d;i++) {
        printf("The coefficient of x^%d:",i);
        scanf("%d",&b[i].coeiff);
        b[n++].exp=i;
    }
}

if(d1=d2) {
    printf("Enter the coefficients of a:\n");
    for(int i=0;i<=d;i++) {
        printf("The coefficient of x^%d:",i);
        scanf("%d",&a[i].coeiff);
        a[m++].exp=i;
    }

    printf("Enter the coefficients of b:\n");
    for(int i=0;i<=d;i++) {
        printf("The coefficient of x^%d:",i);
        scanf("%d",&b[i].coeiff);
        b[n++].exp=i;
    }
}

    //sum of two polynomials

    for(int i=0;i<=d;i++) {
        c[i].coeiff=a[i].coeiff + b[i].coeiff;
        c[l++].exp=i;
    }    

    for(int i=d;i>=0;i--) {
        if (i!=0){
            printf("%dx^%d",c[i].coeiff,c[i].exp);
        }
        if(i==0) {
            printf("%d",c[i].coeiff);
            break;
        }
        printf("+");
    }

}