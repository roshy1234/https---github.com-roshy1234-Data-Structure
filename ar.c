#include <stdio.h>
#include <math.h>
void main()
{
    int n,digit=0,nd=0,r;
    int n;
    for(n=100; n<=1000; n++)
    {
    int a=n;
    while(a>0)
    {
        nd+=1;
        a=a/10;
    }
    int b=n;
    while(b>0)
    {
        r=b%10;
        digit=digit+pow(r,nd);
        b=b/10;
    }
    if (n==digit) printf("%d is armstrong",n);
    }
}