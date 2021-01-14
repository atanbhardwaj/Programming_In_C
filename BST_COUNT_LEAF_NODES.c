#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct tree
{
    struct tree *left;
    int info;
    struct tree *right;
}tree;
void ins(tree **rt, int num)
{
    tree *p;
    if((*rt)==NULL)
    {
        p = (tree *)malloc(sizeof(tree));
        if(p!=NULL)
        {
            p->info = num;
            p->left = NULL;
            p->right = NULL;
            (*rt) = p;
        }
        else
            printf("Not enough Memory Available \n");
    }
    else if(num<((*rt)->info))
        ins(&((*rt)->left),num);
    else
        ins(&((*rt)->right),num);
}
int count_leaf(tree *r)
{
    if(!r)
        return 0;
    else if(!((r->left)&&(r->right)))
        return 1;
    return count_leaf(r->right) + count_leaf(r->left);
}
void main()
{
    int n;char ch;tree *root=NULL;
    do
    {
        printf("Enter the number to be inserted \n");
        scanf("%d",&n);
        ins(&root,n);
        printf("Do you want to continue \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');

    printf("The total number of leaf nodes are %d",count_leaf(root));
}
