#include <stdio.h>
void main()
{
    int n,temp;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&a[i]);
    }
    //Bubble sort algorithm starts here:
    for (int j = 0 ;j<n;j++)
    {
    for(int k=j+1;k<n;k++)
    {
        if (a[j]>a[k])
    {
    temp=a[j];
    a[j]=a[k];
    a[k]=temp;
    }
    }
    }
    for(int l=0;l<n;l++)
    {
    printf("%d ",a[l]);
    }
}