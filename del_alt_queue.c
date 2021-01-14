/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 6: WRITE A C PROGRAM TO DELETE ALTERNATE NODE FROM SINGLY LINKED LIST.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void insert(node **l,int num)
{
    node *p=(node*)malloc(sizeof(node));
    p->info=num;
    p->next=NULL;
    if(*l==NULL)
        *l=p;
    else{
        (*l)->next=p;
        (*l)=p;
    }
}
void del_alt(node *f,node **l)
{
    node *p,*t=f;
    while(t!=NULL&&t->next!=NULL)
    {
        p=t->next;
        if(t->next->next==NULL)(*l)=t;
        t->next=(t->next)->next;
        t=(t->next);
        free(p);
    }
}
void display(node *f)
{
    while(f!=NULL)
    {
        printf("%d ",f->info);
        f=f->next;
    }
}
void main()
{
    node (*fr)=NULL,(*ls)=NULL;
    printf("%d",fr);
    char ch;int n;
    do
    {
        printf("Enter element:");
        scanf("%d",&n);
        insert(&ls,n);
        if(fr==NULL)fr=ls;
        printf("Do you want to continue : \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='Y'||ch=='y');
    del_alt(fr,&ls);
    display(fr);
}
