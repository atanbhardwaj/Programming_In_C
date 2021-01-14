#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node node;
void insert(node **h, int n)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->info = n;
        p->next  =NULL;
        if((*h)==NULL)
            (*h) = p;
        else
        {
            p->next = (*h);
            (*h) = p;
        }
    }
}
void disp(node *hp)
{
    while(hp!=NULL)
    {
        printf("%d",(hp->info));
        hp = hp->next;
    }
}
void main()
{
    node *tp=NULL;
    int num;
    char ch;
    do
    {
        printf("Enter the number \n");
        scanf("%d",&num);
        insert(&tp,num);
        printf("Do you want to continue y/n");
        fflush(stdin);
        scanf("%c",&ch);
    }while((ch=='y')||(ch=='Y'));
    disp(tp);
}
