#include<stdio.h>
#include<stdlib.h>
int main()
{
    int N,i,k,j;
    int *p;
    printf("Enter the limit of array: ");
    scanf("%d",&N);
    p=(int*)malloc(N*sizeof(int));
    for(i=0;i<N;i++)
    {
        scanf("%d",p+i);
    }
    for(i=0;i<N-1;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(*(p+j)==*(p+i))
            {
                for(k=j;k<N;k++)
                    *(p+k)=*(p+k+1);
                N--;
                j--;
            }
        }
    }
    p=(int*)realloc(p,N*sizeof(int));
    for(i=0;i<N;i++)
    {
        printf("%d ",*(p+i));
    }
}
