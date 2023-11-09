#include <stdio.h>
void main() {
    int n,A[100],temp,min;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(int i=0;i<n;i++)
        scanf("%d",A[i]);
    for(int i=0;i<(n-1);i++){
        min=i;
        for(int j=(i+1);j<n;j++){
                if(A[min]>A[j]){
                    temp=A[min];
                    A[min]=A[j];
                    A[j]=temp;
                }
            }
        }
    printf("Sorted array is:");
for(int i=0;i<n;i++)
printf("%d ",A[i]);
printf("\n");
}
