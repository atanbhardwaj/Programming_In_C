#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node node;
node *push(node *,int);
node *pop(node *);
void disp(node *);
void main()
{
    node * top = NULL;
    int n,num;
    char ch;
    do
    {
        printf("Press 1 to Push \nPress 2 to Pop\nPress 3 to display\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
                printf("Enter the element to be pushed\n");
                scanf("%d",&num);
                top = push(top,num);
                break;
            }
            case 2:
            {
                if(top==NULL)
                    printf("Stack is empty \n");
                else
                    top = pop(top);
                break;
            }
            case 3:
            {
                if(top==NULL)
                    printf("Stack is empty\n");
                else
                    disp(top);
                break;
            }
        }
        printf("Do you want to continue y/n?\n");
        fflush(stdin);
        scanf("%c",&ch);
    } while (ch=='y'); 
}
node *push(node *t, int n)
{
    node *p;
    p = (node*)malloc(sizeof(node));
    if(p==NULL)
        printf("Not Enough Memory Available\n");
    else
    {
        p->info = n;
        p->next = t;
        t = p;
    }
    return(t);
}
node *pop(node *t)
{
    node *temp;
    temp = t;
    printf("The poped value is %d\n",(t -> info));
    t=(t->next);
    free(temp);
    return(t);
}
void disp(node *t)
{
    node *k;
    k = t;
    while(k!=NULL)
    {
        printf("%d \n",(k->info));
        k=(k->next);
    }
}