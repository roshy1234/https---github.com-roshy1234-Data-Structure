#include <stdio.h>
void main()
{
    int n, flag=0;
    printf("Enter the number");
    scanf("%d",&n);
    
    for(int i=2;i<n/2;i++)
    {
        if((n%i)==0)
        {
            flag=1;

            break;
        }
    }
    if(n==1) flag=1;
    if(flag==1) 
        {printf("The number is not prime");}
    else 
        { printf("The number is prime");}
}