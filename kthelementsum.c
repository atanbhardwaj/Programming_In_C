#include <stdio.h>
void sort(int arr[], int n)
{
}
void main()
{
    int i, j, n, k, a[50], f = 1;
    printf("Enter the limit: \n");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the element who's some is to be found \n");
    scanf("%d", &k);
    sort(a, n);
    j = n - 1;
    for (i = 0; i < n;)
    {
        if (j <= i)
        {
            f ? printf("The combination in the array does not exist \n") : 0;
            break;
        }
        if ((a[i] + a[j]) > k)
            j--;
        else if (a[i] + a[j] < k)
            i++;
        else
        {
            f = 0;
            printf("Number %d and %d adds up to %d \n", a[i], a[j], k);
            i++;
        }
        // if(a[i]+a[j]>k)
        //     j--;
        // else if(a[i]+a[j]<k)
        //     i++;
        // else
        // {
        //     f=0;
        //     printf("Number %d and %d adds up to %d \n",a[i],a[j],k);
        //     i++;
        // }
    }
}
