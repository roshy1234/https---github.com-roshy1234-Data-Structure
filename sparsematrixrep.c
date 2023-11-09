#include <stdio.h>
void main() {
    int a[20][20],b[20][20],m,n,k;

//input number of rows and column of sparse matrix
    printf("Enter the number of rows of a:");
    scanf("%d",&m);

    printf("Enter the number of columns of a:");
    scanf("%d",&n);

//input sparse matrix
    printf("Enter the elements of a:\n");
    for(int i =0;i<m;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }

    k=1;

    b[0][0]=m;
    b[0][1]=n;

    for(int i =0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(a[i][j]!=0) {
                    b[k][0]=i;
                    b[k][1]=j;
                    b[k][2]=a[i][j];
                    k++;
                }
            }
        }


    b[0][2]=k-1;
    for(int i=0;i<k;i++) {
        for(int j=0;j<3;j++) {
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }

}