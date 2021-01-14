#include<stdio.h>
void main()
{
    int i,j,m,n,max,min,f;
    printf("Enter the limit1: \n");
    scanf("%d",&m);
    printf("Enter the limit2: \n");
    scanf("%d",&n);
    min = m;
    max = n;
    if(n<m)
    {
        max = m;
        min = n;
    }
    for(i=min;i<=max;i++,f=1)
    {
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
                f=0;
        }
        if(f)
            printf(" %d",i);
    }
}