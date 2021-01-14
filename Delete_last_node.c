#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void create(node **t, int num)
{
    node *p=(node *)malloc(sizeof(node));
    p->info=num;
    p->next=NULL;
    if((*t)==NULL)
        (*t)=p;
    else
    {
        p->next=(*t);
        (*t)=p;
    }
}
void del_last(node *t)
{
    node *y=t,*h;
    while(((y->next)->next)!=NULL)
    {
        y = y->next;
    }
     h = y;
    y = (y->next);
    free(y);
    h->next=NULL;
}
void disp(node *t)
{
    while(t!=NULL)
    {
        printf("%d",(t->info));
        t = t->next;
    }
}
void main()
{
    int num;
    node *top = NULL;
    char ch;
    do
    {
        printf("Enter the element \n");
        scanf("%d",&num);
        create(&top,num);
        printf("Do you want to continue \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    del_last(top);
    disp(top);
}
