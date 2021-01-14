/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 2: WRITE A C PROGRAM TO IMPLEMENT A PRIORITY QUEUE USING SINGLY LINKED LIST.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int info,priority;
    struct node *next;
}node;
void create(node **l, node **r, int n,int pr)
{
    node *p,*t=(*l);
    p = (node *)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->info = n;
        p->priority = pr;
        p->next = NULL;
        if((*l) == NULL)
        {
            (*l) = p;
            (*r) = p;
        }
        else if(pr>((*r)->priority))
        {
            (*r)->next = p;
            (*r) = p;
        }
        else if(pr<((*l)->priority))
        {
            p->next = (*l);
            (*l) = p;
        }
        else
        {
            while(pr>((t)->next->info))
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
    int num,prr;
    node *left = NULL, *right = NULL;
    char ch;
    do
    {
        printf("Enter the element \n");
        scanf("%d",&num);
        printf("Enter the priority \n");
        scanf("%d",&prr);
        create(&left, &right, num,prr);
        printf("Do you want to continue \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='Y'||ch=='y');
    disp(left);
}
