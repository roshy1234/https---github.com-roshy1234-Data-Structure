#include <stdio.h>
#define S 5
void main(){
    int m,n;
    printf("Enter the order of two matrix");
    scanf("%d%d",&m,&n);
    int a[S][S],b[S][S],t1[20][3],t2[20][3],t3[20][3];
    printf("Enter the elements of first matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of second matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }

    t1[0][0]=m;
    t2[0][0]=m;
    t3[0][0]=m;
    t1[0][1]=n;
    t2[0][1]=n;
    t3[0][1]=n;

    int k=1,l=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=0) {
                t1[k][0]=i;
                t1[k][1]=j;
                t1[k][2]=a[i][j];
                k++;
            }
            if(b[i][j]!=0) {
                t2[l][0]=i;
                t2[l][1]=j;
                t2[l][2]=b[i][j];
                l++;
            }
        }
    }    

    t1[0][2]=k-1;
    t2[0][2]=l-1;

    int i=1,j=1,c=1;

    while(i<=k && j<=l){
        if(t1[i][0]<t2[j][0] || (t1[i][0]==t2[j][0] && t1[i][1]<t2[j][1])){
            t3[c][0]=t1[i][0];
            t3[c][1]=t1[i][1];
            t3[c][2]=t1[i][2];
            c++;
            i++;
        }
        else if(t1[i][0]>t2[j][0] || (t1[i][0]==t2[j][0] && t1[i][1]>t2[j][1])){
            t3[c][0]=t2[j][0];
            t3[c][1]=t2[j][1];
            t3[c][2]=t2[j][2];
            c++;
            j++;
        }
        else{
            t3[c][0]=t1[i][0];
            t3[c][1]=t1[i][1];
            t3[c][2]=t1[i][2]+t2[j][2];
            c++;
            i++;
            j++;
        }
    }

    while(i<=k){
        t3[c][0]=t1[i][0];
        t3[c][1]=t1[i][1];
        t3[c][2]=t1[i][2];
        c++;
        i++;
    }

    while(j<=l){
        t3[c][0]=t2[j][0];
        t3[c][1]=t2[j][1];
        t3[c][2]=t2[j][2];
        c++;
        j++;
    }

    t3[0][2]=c-1;

    for(int i=0;i<c-1;i++) {
        for(int j=0;j<3;j++) {
            printf("%d ",t3[i][j]);
        }
        printf("\n");
    }
}

