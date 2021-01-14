#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void create(node **t,node **h,int n)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    (*h)=p;
    if(p!=NULL)
    {
        p->info=n;p->next=NULL;
        (*t)->next=p;
        (*t)=p;
    }
}
void middle(node *head)
{
    node *s = head, *f = head;
    if(head!=NULL)
    {
        while(f!=NULL&&(f->next)!=NULL)
        {
            f = f->next->next;
            s=s->next;
        }
    }
    printf("The middle element is %d",(s->info));
}
void main()
{
    node *t=NULL,*h=NULL;
    int num;
    char ch;
    do
    {
        printf("Enter the element\n");
        scanf("%d",&num);
        create(&t,&h,num);
        printf("Do you want to continue\n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y');
    middle(h);
}

