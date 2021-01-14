/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 4: WRITE A C PROGRAM TO IMPLEMENT STACK USING LINKED LIST AND THEN DISPLAY STACK
FROM BOTTOM TO TOP.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void push(node **,int);
void pop(node **);
void disp(node *);
void main()
{
    node *top = NULL;
    int n,num;
    char ch;
    do
    {
        printf("Press 1 to Push \nPress 2 to Pop\nPress 3 to display\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
                printf("Enter the element to be pushed\n");
                scanf("%d",&num);
                push(&top,num);
                break;
            }
            case 2:
            {
                if(top==NULL)
                    printf("Stack is empty \n");
                else
                    pop(&top);
                break;
            }
            case 3:
            {
                if(top==NULL)
                    printf("Stack is empty\n");
                else
                    disp(top);
                break;
            }
        }
        printf("Do you want to continue y/n?\n");
        fflush(stdin);
        scanf("%c",&ch);
    } while (ch=='y'||ch=='Y');
}
void push(node **t, int n)
{
    node *p;
    p = (node*)malloc(sizeof(node));
    if(p==NULL)
        printf("Not Enough Memory Available\n");
    else
    {
        p->info = n;
        p->next = *t;
        *t = p;
    }
}
void pop(node **t)
{
    node *temp;
    temp = (*t);
    (*t) = (*t)->next;
    printf("The popped value is %d\n",(temp-> info));
    free(temp);
}
void disp(node *t)
{
    if(t==NULL)
        return;
    else
    {
        disp(t->next);
        printf("%d ", (t->info));
    }
    printf("\n");
}
