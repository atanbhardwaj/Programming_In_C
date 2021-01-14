#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int info,priority;
    struct node *next;
}node;
void create(node **l, node **r, int n,int pt)
{
    node *p,*t=(*l);
    p = (node *)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->info = n;
        p->priority = pt;
        p->next = NULL;
        if((*l) == NULL)
        {
            (*l) = p;
            (*r) = p;
        }
        else if(pt>((*r)->priority))
        {
            (*r)->next = p;
            (*r) = p;
        }
        else if(pt<((*l)->priority))
        {
            p->next = (*l);
            (*l) = p;
        }
        else
        {
            while(pt>((t)->next->priority))
            {
                t = t->next;
            }
            p->next = t->next;
            t->next = p;
        }
    }
    else
        printf("Not Enough Memory Available \n");
}
void disp(node *h)
{
    while(h!=NULL)
    {
        printf("%d ",(h->info));
        h = h->next;
    }
}
void main()
{
    int num,pr;
    node *left = NULL, *right = NULL;
    char ch;
    do
    {
        printf("Enter the element \n");
        printf("Enter the priority \n");
        scanf("%d%d",&num,&pr);
        create(&left, &right, num, pr);
        printf("Do you want to continue \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='Y'||ch=='y');
    disp(left);
}
