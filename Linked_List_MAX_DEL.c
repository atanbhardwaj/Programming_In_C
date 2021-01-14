#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void insert(node **h, int n)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->info = n;
        p->next = NULL;
        if(*(h)==NULL)
            *(h) = p;
        else
        {
            p->next = *(h);
            *(h) = p;
        }
    }
    else
        printf("Not Enough Memory Available \n");
}
void del_max(node *j)
{
    node *t = j,*l = j,*s,*w=j;
    int max;
    max  = t->info;
    t = t->next;
    while(t!=NULL)
    {
        if(max<(t->info))
        {
            max = t->info;
            s = t;
        }
        t = t->next;
    }
    if(s==j)
        j = j->next;
    else
    {
        while(l!=s)
        {
            l = l->next;
        }
        if(s->next == NULL)
            l->next = NULL;
        else
            l->next = l->next->next;
    }
    free(s);
    while(j!=NULL)
        {
            printf("%d",(j->info));
            j = j->next;
        }


}

void main()
{
    node *head = NULL;
    int num; char ch;
    do
    {
        printf("Enter the element \n");
        scanf("%d",&num);
        insert(&head,num);
        printf("Do you want to continue y/n \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    del_max(head);
}
