#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *prev;
    int info;
    struct node *next;
}node;
void create(node **l, node **r, int n)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->info = n;
        if((*l) == NULL && (*r) == NULL)
        {
            (*l) = p;
            (*r) = p;
            (*l)->prev = NULL;
        }
        else
        {
            (*r) -> next = p;
            p->prev = (*r);
            (*r) = p;
        }

    }
}
void d(node *h)
{
    while(h!=NULL)
    {
        printf("%d ",(h->info));
        h = h->prev;
    }
}
void main()
{
    int n;
    char ch;
    node *lf = NULL, *rt = NULL;
    do
    {
        printf("Enter the element \n");
        scanf("%d",&n);
        create(&lf, &rt, n);
        printf("Do you want to continue y/n \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch == 'y' || ch == 'Y');
    d(rt);
}
