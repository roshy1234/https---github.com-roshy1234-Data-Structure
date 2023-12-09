#include <stdio.h>
void main()
{
    int n,b,f;
    printf("Enter the array size");
    scanf("%d",&n);
    int a[n];
    printf("Enter array :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter search key:");
    scanf("%d", &b);
    //linear search algorithm
    f=0;
    for(int j=0;j<n;j++)
    {
        if(a[j]==b)
        {
        printf("%d is found at %d",b,j);
        f=1;
        }
    }
    if(f==0) printf("%d not found",b);

}
    