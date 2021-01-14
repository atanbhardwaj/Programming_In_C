#include<stdio.h>
#include<stdlib.h>
#define max 100
int insert(int [],int);
int serve(int [],int,int);
void disp(int [],int,int);
void main()
{
    int q[max], f=-1,r=-1,n;
    char ch;
    do
    {
        printf("Press 1 to insert\nPress 2 to Serve\nPress 3 to display");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
                if(((f==0)&&(r==(max-1)))||(f==r+1))
                    printf("Overflow\n");
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
                    printf("Underflow");
                else
                {
                    f=serve(q,f,r);
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
        printf("Do you want to continue y/n\n");
        fflush(stdin);
        scanf("%c",&ch);
    } while (ch=='y');
}
int insert(int q[], int r)
{
    int x;
    printf("Enter the value:\n");
    scanf("%d",&x);
    if(r==max-1)
        r = 0;
    else
        r++;
    q[r] = x;
    return(r);
}
int serve(int q[],int f,int r)
{
    int x=0;
    x = q[f];
    printf("%d",x);
    if(f==r)
        f=-1;
    else if(f==max-1)
        f=0;
    else
        f++;
    return(f);
}
void disp(int q[],int f,int r)
{
    int i;
    if(f<=r)
    {
        for(i=f;i<=r;i++)
            printf("%d",q[i]);
    }
    else
    {
        for(i=f;i<=max-1;i++)
            printf("%d",q[i]);
        for(i=0;i<=r;i++)
            printf("%d",q[i]);
    }
}