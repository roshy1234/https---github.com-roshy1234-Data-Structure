#include <stdio.h>
void main()
{
    int n,*a,temp=0;
    printf("Enter the number of elements ");
    scanf("%d",&n);
    printf("Enter the elements of the array :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(*(a+j)<*(a+i))
            {
                temp=*(a+j);
                *(a+j)=*(a+i);
                *(a+i)=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
            printf("%d",*(a+i));
    }
}