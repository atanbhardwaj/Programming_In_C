#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    struct tree *left;
    int info;
    struct tree *right;
}tree;

void create(tree **r, int n)
{
    tree *p;
    if(!(*r))
    {
        p=(tree*)malloc(sizeof(tree));
        p->info=n;
        p->left=p->right=0;
        (*r)=p;
    }
    else if((*r)->info>n)
        create(&((*r)->left),n);
    else    create(&((*r)->right),n);
}

int cl(tree *ro)
{
    if(!ro) return 1;
    else {
            if(cl(ro->left)==0&&cl(ro->right)==0)
            return(cl(ro->left)+cl(ro->right)+1);}
}

int main()
{
    tree *root=0;
    int c,num; char ch;
    printf("Create a BST \n");
    do
    {
        printf("Enter the information \n");
        scanf("%d",&num);
        create(&root,num);
        printf("Do you want to continue Y/N \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='Y'||ch=='y');
    printf("The total number of leaf nodes in the BST are %d \n",cl(root));
}
