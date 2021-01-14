#include<stdio.h>
void main()
{
    int i,j,n,a[30];
    printf("Enter the limit : \n");
    scanf("%d",&n);
    printf("Enter the elements of the array \n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    j = a[n-1];
    printf("The leaders are %d",j);
    for(i=n-1;i>0;)
    {
        if(a[--i]>j)
        {
            j = a[i];
            printf(" %d",a[i]);
        }
    }
}