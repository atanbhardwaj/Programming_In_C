/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 8: WRITE A C PROGRAM TO CREATE A BINARY SEARCH TREE AND THEN WRITE C FUNCTION FOR FOLLOWING OPERATIONS
(i) COUNT TOTAL NUMBER OF NODES.
(ii) COUNT TOTAL NUMBER OF LEAF NODES.
*/
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
void count_nodes(tree *r, int *f)
{
    if(r==NULL)
        return;
    else
    {
        (*f)++;
        count_nodes(r->left,f);
        count_nodes(r->right,f);
        return;
    }
}
void count_leaf(tree *r, int *f)
{
    if(r==NULL)
        return;
    else
    {
        if((r->left)==NULL&&(r->right)==NULL)
            (*f)++;
        count_leaf(r->left,f);
        count_leaf(r->right,f);
        return;
    }
}
void main()
{
    int n,a,c=0,l=0;char ch;tree *root=NULL;
    do
    {
        printf("Enter the element to be inserted \n");
        scanf("%d",&n);
        ins(&root,n);
        printf("Do you want to continue \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    do
    {
        printf("Enter you choice \n Press 1 to count total number of nodes \n Press 2 to countleaf nodes \n");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            count_nodes(root,&c);
            printf("The total number of nodes are %d \n",c);
            break;
        case 2:
            count_leaf(root,&l);
            printf("The total number of leaf nodes are %d \n",l);
            break;
        }
        printf("Do you want to continue \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
}
