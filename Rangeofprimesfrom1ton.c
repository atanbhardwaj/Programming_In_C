#include<stdio.h>
void main()
{
    int i,j,n,c;
    printf("Enter the upper limit: \n");
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        int c=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
                c++;
        }
        if(c==2)
            printf(" %d",i);
    }
}