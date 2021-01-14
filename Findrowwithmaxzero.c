#include<stdio.h>
void main()
{
    int i,j,m,n,a[30][30],z,max,r;
    printf("Enter row limit: \n");
    scanf("%d",&m);
    printf("Enter column limit: \n");
    scanf("%d",&n);
    printf("Input elements into matrix:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);   
    }
    max=0;
    r=0;
    z =0;
    for(i=0;i<m;i++)
    {
        //printf("[");
        if(max<z)
        {
            max=z;
            printf("max is %d",max);
            printf("\n");
        }
        z=0;        
        
        for(j=0;j<n;j++)
            {
                if(a[i][j]==0)
                {
                    printf(" %d",a[i][j]);
                printf("\n");
                    z++;
                    r = i;
                }
               // printf(" %d",a[i][j]);
            }
           //printf(" ]");
            //printf("\n");
             

    }
    r+=1;
    printf("\n");
    printf("row with maximum zeros is: %d",r);
    
}