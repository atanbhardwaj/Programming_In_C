#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void create(node **h, int num)
{
    node *p=(node*)malloc(sizeof(node));
    p->info = num;
    p->next = NULL;
    if((*h)==NULL)
        (*h)=p;
    else
    {
        p->next = (*h);
        (*h)=p;
    }
}
void insert(node **t, int pos,int num)
{
    node *p=(*t),*tmp,*c;
    int n=1;
    while(n!=pos)
    {
        if(n==(pos-1))
        {
            tmp = p;
            break;
        }
        p = p->next;
        n++;
    }
    if(pos==1)
    {
    c=(node*)malloc(sizeof(node));
    c->info=num;
    c->next=(*t);
    (*t)=c;
    }
    else
    {
    c=(node*)malloc(sizeof(node));
    c->info=num;
    c->next=tmp->next;
    tmp->next=c;
    }
}
void disp(node *t)
{
    while(t!=NULL)
    {
        printf("%d ",(t->info));
        t=t->next;
    }
}
void main()
{
    int num,pos,inf;
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
    printf("Enter the position \n");
    scanf("%d",&pos);
    printf("Enter the information \n");25
    scanf("%d",&inf);
    insert(&top,pos,inf);
    disp(top);
}


