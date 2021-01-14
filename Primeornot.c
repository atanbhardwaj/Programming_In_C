#include<stdio.h>
void main()
{
    int i,n,c = 0;
    printf("Enter the number:\n");
    scanf("%d",&n);
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            c = 1;
            break;
        }
    }
    if(c==0)
        printf("Prime");
    else
        printf("Not Prime"); 
}