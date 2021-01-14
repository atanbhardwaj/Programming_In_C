#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node node;
void insert(node **f, node **r, int n)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->info = n;
        p->next  =NULL;
        if((*f)==NULL)
        {
            (*f) = p;
            (*r) = p;
        }
        else
        {
            (*r)->next = p;
            (*r) = p;
        }
    }
    else
        printf("Not enough memory Available \n");
}
void disp(node *hp)
{
    while((hp)!=NULL)
    {
        printf("%d ",(hp->info));
        hp = hp->next;
    }
}
void main()
{
    node *fp = NULL, *rp = NULL;
    int num;
    char ch;
    do
    {
        printf("Enter the number \n");
        scanf("%d",&num);
        insert(&fp,&rp,num);
        printf("Do you want to continue y/n");
        fflush(stdin);
        scanf("%c",&ch);
    }while((ch=='y')||(ch=='Y'));
    rp = fp;
    disp(rp);
}
