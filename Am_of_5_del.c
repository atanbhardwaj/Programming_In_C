#include<stdio.h>
#include<stdlib.h>
void del(int *k, int l)
{
    int i,j;
    for(i=0;i<l;i++)
    {
        if(*(k+i)%5==0)
        {
            for(j=i;j<(l-1);j++)
                *(k+j) = *(k+j+1);
            i--;
            l--;
        }
    }
    k = realloc(k,l*sizeof(int));
    for(i=0;i<l;i++)
        {printf("%d ",*(k+i));}
    printf("\n");
    printf("%d is the size of array",l);
}
void main()
{
    int *p,n,i;
    printf("Enter the limit\n");
    scanf("%d",&n);
    p = (int *)calloc(n,sizeof(int));
    printf("Enter the elements \n");
    for(i=0;i<n;i++)
        scanf("%d",(p+i));
    del(p,n);
}
