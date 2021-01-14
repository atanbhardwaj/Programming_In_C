#include<stdio.h>
void main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(k=5;k>i;k--)
            {
                printf(" ");
            }
        for(j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}