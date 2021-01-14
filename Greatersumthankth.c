#include<stdio.h>
void main()
{
    int i,j,n,k,a[50], f=1;
    printf("Enter the limit: \n");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element who's some is to be found \n");
    scanf("%d",&k);
    j =  n-1;
    for(i = 0; i<n;)
    {
         if(j<=i)
        {
            f ? printf("The combination in the array does not exist \n"):0;
            break;
        }
        if(a[i]+a[j]>k)
            {
            f=0;
            printf("Number %d and %d sum is greater than %d \n",a[i],a[j],k);
            i++;
            if(i==j)
            {
                //printf("Number %d and %d sum is greater than %d \n",a[i],a[j],k);
                i=0;j--;
            }
            }
        else 
            i++;
    }
}
