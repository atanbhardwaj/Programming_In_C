#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct tt
{
    struct tt *left;
    int info;
    struct tt *right;
}tt;
void create(tt **rt, int num)
{
    tt *p;
    if((*rt)==NULL)
    {
        p = (tt *)malloc(sizeof(tt));
        if(p!=NULL)
        {
            p->info = num;
            p->left = NULL;
            p->right = NULL;
            (*rt) = p;
        }
        else printf("Not enough Memory \n");
    }
    else if(num<(*rt)->info)
        create((&((*rt)->left)),num);
    else
        create((&((*rt)->right)),num);
}
void pre_order(tt *r)
{
    if(r==NULL)
        return;
    else
    {
        printf("%d ",(r->info));
        pre_order((r->left));
        pre_order((r->right));
    }
}
void main()
{
    int n;
    char ch;
    tt *root = NULL;
    do
    {
        printf("Enter the number to be inserted \n");
        scanf("%d",&n);
        create(&root, n);
        printf("Do you want to continue \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch == 'Y');
    pre_order(root);
}
