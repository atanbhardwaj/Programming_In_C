#include<stdio.h>
#include<stdlib.h>
#define max 100
int insert(int a[], int r)
{
    int x;
    printf("Enter the element to be inserted \n");
    scanf("%d",&x);
    if(r==(max-1))
        r=0;
    else
        r++;
    a[r]=x;
    return(r);
}
int serve(int a[], int f, int r)
{
    int x=0;
    x=a[f];
    printf("Element served is %d",x);
    if(f==r)
        f=-1;
    else if(f==(max-1))
        f=0;
    else
        f++;
    return(f);
}
void disp(int a[],int f, int r)
{
    int i;
    if(f<=r)
    {
        for(i=f;i<=r;i++)
            printf("%d\n",a[i]);
    }
    else
    {
        for(i=f;i<=(max-1);i++)
            printf("%d\n",a[i]);
        for(i=0;i<=r;i++)
            printf("%d\n",a[i]);
    }
}
void main()
{
    int q[max],f=-1,r=-1,n;
    char ch;
    do
    {
        printf("\nPress 1 to insert\n 2 to serve\n 3 to display\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
                if((f==0&&(r==(max-1)))||f==(r+1))
                    printf("Queue is full\n");
                else
                {
                    r = insert(q,r);
                    if(f==-1)
                        f=0;
                }
                break;
            }
            case 2:
            {
                if(f==-1&&r==-1)
                    printf("Underflow\n");
                else
                {
                    f = serve(q,f,r);
                    if(f==-1)
                        r=-1;
                }
                break;
            }
            case 3:
            {
                if(f==-1&&r==-1)
                    printf("Empty\n");
                else
                    disp(q,f,r);
            }
            break;
        }
        printf("Do you want to continue\n");
        fflush(stdin);
        scanf("%c",&ch);
    } while ((ch)=='y');
}