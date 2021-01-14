#include<stdio.h>
#define max 100//limit of stack
int push(int x[],int k,int n)//Function to insert an
//element at the top of stack
{
    x[k]=n;
}
int pop(int x[],int k)//function to pop
//top element of stack
{
    printf("Popped value is %d\n",x[k]);
}
void display(int x[],int k)//function to display
//element of stack
{
    for(;k>=0;k--)
        printf("%d\n",x[k]);
}
void main()
{
    int arr[max],top=-1,n;
    int ch;char c;
    do
    {
        printf("Press :\n 1. Push \n 2. Pop \n");
        printf(" 3. Display \n");//Menu
        printf("\n Enter your choice: \n");
        scanf("%d",&ch);
        fflush(stdin);
        switch(ch)
        {
        case 1:
            if(top==max-1)//Extreme Condition check
                printf("Stack Overflow\n");
            else
            {
                printf("Enter value to be pushed: ");
                scanf("%d",&n);
                push(arr,++top,n);//function call
            }
            goto end;
        case 2:
             if(top==-1)//Extreme Condition check
                printf("Stack is empty\n");
             else
                pop(arr,top--);//function call
             goto end;
        case 3:
             if(top==-1)//Extreme Condition check
                printf("Stack is empty\n");
             else
                display(arr,top);//function call
             goto end;
        end:
             printf("Do you want to continue y/n \n");
             fflush(stdin);
             scanf("%c",&c);
        }
    }while(tolower(c)=='y');
}
