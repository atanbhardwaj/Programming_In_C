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
int count_nodes(tree *r)
   {
    if(!r)
        return 0;
    return count_nodes(r->left) + count_nodes(r->right) + 1;
//     if(!r)
//     return 0;
//     if(r->right != NULL)
//     return 1 + count_nodes(r->right) + count_nodes(r->left);
//    return count_nodes(r->left);
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
    printf("The total number of nodes are %d",count_nodes(root));
}
