/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 1: WRITE A C PROGRAM TO FIND UNION AND INTERSECTION OF TWO GIVEN SINGLY LINKED LIST.ORDER OF ELEMENTS IN
OUTPUT LISTS DOESNT MATTER.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void create(node **tpp, int num)
{
    node *p=(node *)malloc(sizeof(node));
    if(p!=NULL)
    {
        p->info = num;
        p->next = NULL;
        if((*tpp)==NULL)
            (*tpp)=p;
        else
        {
            p->next=(*tpp);
            (*tpp) = p;
        }
    }
    else
        printf("Not Enough Memory Available \n");
}
void uni(node *t1, node *t2,node **u,int cn)
{
    node *tmp1 = t1,*inside=t2,*k;
    int element;
    while(tmp1!=NULL)
    {
        create(&(*u),(tmp1->info));
        tmp1=(tmp1->next);
    }
    while(cn!=0)
    {
        element = 0;
        k = (*u);
        while(k!=NULL)
        {
            if((inside->info)==(k->info))
            {
                element++;
                break;
            }
            k = k->next;
        }
        if(element==0)
          create(&(*u),(inside->info));
        inside = inside->next;
        cn--;
    }
    printf("The union is:");
    while((*u)!=NULL)
    {
        printf("%d ",((*u))->info);
        (*u) = ((*u)->next);
    }
    printf("\n");
}
void inter(node *f, node *s, node **in,int count)
{
    node *t,*p;
    int counter;
    while(count!=0)
    {
        t=s;
        counter = 0;
        while(t!=NULL)
        {
            if((t->info)==(f->info))
            {
                counter++;
                break;
            }
            t = t->next;
        }
        if(counter>0)
            create(&(*in),(f->info));
        f = f->next;
        count--;
    }
    printf("The intersection is: ");
    while((*in)!=NULL)
    {
        printf("%d ",((*in)->info));
        (*in) = (*in)->next;
    }
    printf("\n");
}
void main()
{
    int n1,n2,count = 0,choice;
    char ch;
    node *tp1 = NULL, *tp2 = NULL,*up = NULL,*inp = NULL;
    printf("Enter the elements of 1st LL \n");
     do
    {
        printf("Enter element :\n");
        scanf("%d",&n1);
        create(&tp1,n1);
        printf("Do you want to continue y/n \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    printf("Enter the element of 2nd LL \n");
    do
    {
        printf("Enter element :\n");
        scanf("%d",&n2);
        count++;
        create(&tp2,n2);
        printf("Do you want to continue y/n \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');

    do
    {
        printf("Enter your choice \nPress 1 for Union\nPress 2 for Intersection\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
             uni(tp1,tp2,&up,count);
             break;
            }
        case 2:
            {
            inter(tp1,tp2,&inp,count);
            }
        }
        printf("Do you want to continue y/n \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
}

