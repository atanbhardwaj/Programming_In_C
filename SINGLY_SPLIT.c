/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 5: WRITE A C PROGRAM TO SPLIT A SINGLY LINKED LIST, THE NODE INFORMATION IS GIVEN BY THE USER AT WHICH
LINKED LIST HAS TO SPLIT.*/

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
    if(p!=NULL)
    {
        p->info = num;
        p->next = NULL;
        if((*h)==NULL) (*h)=p;
        else
        {
            p->next = (*h);
            (*h)=p;
        }
    }
}
void split(node *f,int infor)
{
    node *f1,*f2,*t;
    t=f;
    while(t!=NULL)
    {
        if((t->info)==infor)
        {
            f1 = t;
            f2 = (t->next);
            f1->next = NULL;
            break;
        }
        else if((((t->next)->info)==infor)&&((t->next)->next)==NULL)
        {
            f1 = f;
            f2 = t->next;
            t->next = NULL;
            break;
        }
        else
        {
                t  = t->next;
                if((t->next)->info==infor)
                {
                    f1 = f;
                    f2 = (t->next);
                    t->next = NULL;
                    break;
                }
        }
    }
    printf("This is list 1 \n");
    while(f1!=NULL)
    {
        printf("%d ",(f1->info));
        f1 = (f1->next);
    }
    printf("\n");
    printf("This is list 2 \n");
    while(f2!=NULL)
    {
        printf("%d ",(f2->info));
        f2 = f2->next;
    }
}
void disp(node *h)
{
    while(h!=NULL)
    {
        printf("%d",(h->info));
        h = h->next;
    }
}
void main()
{
    int n,infor;char ch;node *top = NULL;
    do
    {
        printf("Enter the element\n");
        scanf("%d",&n);
        create(&top,n);
        printf("Do you want to continue y/n \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    printf("Enter the split information \n");
    scanf("%d",&infor);
    split(top,infor);
}
