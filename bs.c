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
    // binary search using array 
    int x;
    printf("Enter the number to be searched:");
    scanf("%d",&x);
    int upper,lower,mid;
    lower = 0 ;upper = (n-1) ; 
    int f=0;
    for(int i=0;i<n;i++)
    {
        mid=(lower + upper)/2;
        if (a[mid]==x)
        {
            printf("The element %d is found at index %d",x,mid);
            f=1;
            break;
        }
        else if(a[mid]<x)
        {
            lower=mid;
        }
        else if(a[mid]>x)
        {
            upper=mid;
        }
    }
    if(f==0)
    {
        printf("Element not found");
    }
}