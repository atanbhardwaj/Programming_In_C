//OPTIMISED : COMPLEXITY O(n)
#include<stdio.h>
void main()
{
    int i,a[30],res,n,j=1, in=2;
    printf("Enter the limit \n");
    scanf("%d",&n);
    printf("Enter the elements in the array \n");
    for(i=0; i<n-1; i++)
        scanf("%d",&a[i]);
    i=1;
    res = a[0];
    while(1)
    {
        if(i<n-1)
        {
            res ^= a[i];
            i++;
        }
        if(in!=n+1)
        {
            j ^= in;
            in++;
        }
        else
            break;
    }
    res ^= j;
    printf("The Missing Element is: %d ",res);
}
