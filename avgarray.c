
#include <stdio.h>
void main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&a[i]);
    }
    float sum=0;
    for(int j=0;j<n;j++)
    {
        sum+=a[j];
    }
    printf("Average is :%f",sum/n);
}