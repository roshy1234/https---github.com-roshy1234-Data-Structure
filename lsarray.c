#include <stdio.h>
void main()
{
    int n,b,f;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter %d element:",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be searched:");
    scanf("%d", &b);
    //linear search algorithm
    f=0;
    for(int j=0;j<n;j++)
    {
        if(a[j]==b)
        {
        printf("%d is the element of index %d",b,j);
        f=1;
        }
    }
    if(f==0)
    {
        printf("%d not found in array",b);
    }
}
    