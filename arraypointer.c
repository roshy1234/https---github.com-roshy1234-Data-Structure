#include<stdio.h>
#include<malloc.h>
void main()
{ int i,n,temp,j;
int *p = malloc(30 * sizeof(int)); // equivalent to int p[30];
printf("Enter the size of array:");
scanf("%d",&n);
for(i=0;i<n;i++)
{scanf("%d",p+i); }
for(i=0;i<n;i++)
{for(j=i+1;j<n;j++)
{
    if(*(p+j) < *(p+i))
{ temp = *(p+j);
*(p+j) = *(p+i);
*(p+i) = temp;}
}
}
printf("Array Content\n");
for(i=0;i<n;i++)
{ printf("%d\t",*(p+i)); }}
