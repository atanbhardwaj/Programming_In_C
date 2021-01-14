//OPTIMISED : COMPLEXITY O(n)
#include<stdio.h>

/*void f()
{

    int i,a[30],c, n;
    printf("Enter the limit \n");
    scanf("%d",&n);
    for(i=0; i<n*3-1; i++)
        scanf("%d",&a[i]);
    i=0;
A:
    c=1;
    while(a[i]==a[++i])
        c++;

    if(c==2)
        printf("%d", a[i-1]);
    else
        goto A;
}*/

void main()
{
    //f();

    int i,a[30],res,n,j=1,k,k1=0, counter=3,in=1;
    printf("Enter the limit \n");
    scanf("%d",&n);
    k = (n*3)-1;
    for(i=0; i<k; i++)
        scanf("%d",&a[i]);

    i=1;
    res = a[0];
    while(1)
    {
        if(i<k)
        {
            res ^= a[i];
            i++;
        }
        if((in*3)<=(n*3))
        {
            j ^= in;
            if(k1==0)
            {
                in = 1;
                k1++;
            }
            else
            {
                if((k1==1)&&(in==1))
                    in++;
            }
            if((k1==1)&&(in!=1))
            {
                if(counter != 0)
                    counter--;
                else
                {
                    in++;
                    counter = 2;
                }
            }
        }
        else
            break;
    }
    res ^= j;
    printf("The Element repeated twice is: %d ",res);
}
