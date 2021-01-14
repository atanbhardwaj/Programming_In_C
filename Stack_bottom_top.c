/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 4: WRITE A C PROGRAM TO IMPLEMENT STACK USING LINKED LIST AND THEN DISPLAY STACK
FROM BOTTOM TO TOP.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void create(node **t, int num)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    p->info = num;
    p->next = NULL;
    if(p!=NULL)
    {
        if((*t)==NULL)
            (*t) = p;
        else
        {
            p->next = (*t);
            (*t) = p;;
        }
    }
    else
        printf("Not Enough Memory Available \n");
}
void display(node *h)
{
    if(h==NULL)
        return;
    else
    {
        display(h->next);
        printf("%d ", (h->info));
    }
}
void main()
{
    int num;
    node *top = NULL;
    char ch;
    do
    {
        printf("Enter the element \n");
        scanf("%d",&num);
        create(&top,num);
        printf("Do you want to continue \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    printf("Stack from bottom to top is \n");
    display(top);
}
