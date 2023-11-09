#include <stdio.h>
void main()
{
    int n,large;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&a[i]);
    }
    large=a[0];
    for (int i=0;i<n;i++)
    {
    if(a[i]>large)
    {
        large=a[i];
    }
    }
    printf("the largest number in array is %d",large);
}
