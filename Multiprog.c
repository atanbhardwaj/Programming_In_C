/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 3: WRITE A C PROGRAM USING CIRCULAR LINKED LIST DO PROCESSOR SCHEDULING FOR N
PROCESSES. EVERY PROCESS IS GIVEN A CPU TIME SLOT OF 10 SECONDS AT A TIME. FIND OUT WHICH PROCESS
WILL BE COMPLETE WHEN AND WHAT WILL BE THE TOTAL WAITING TIME FOR EVERY PROCESS.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}node;
node* push()
{
    node *p=(node*)malloc(sizeof(node));
    if(p==NULL)printf("Not enough memory\n");
    else{
    scanf("%d",&(p->info));
    p->next=NULL;
    return(p);}
}
void cal_time(node *f,node *r,int n)
{
    node *temp=f;int c=0,row=1;
    while(n!=0)
    {
        temp->info=((temp->info)-10);
        c++;
        if(c%n==0)
            row++;
        if(temp->info<=0)
        {
            n--;
            while((f->next)!=(temp))
            {
                f=(f->next);
            }
            f->next=(temp->next);
            free(temp);
            printf("finishing time : %d\n",(c*10));
            printf("Waiting time : %d\n",((c*10)-(row*10)));
        }
        temp=(temp->next);
    }
}
void main()
{
    int n,num;
    node *f=NULL,*r=NULL;
    printf("Enter the number of programs:");
    scanf("%d",&n);num=n;
    while(n!=0)
    {
        printf("Enter the execution time:");
            if(f==NULL){r=push();f=r;}
            else{ r->next=push();r=(r->next);}
        n--;
    }
    r->next=f;
    cal_time(f,r,num);
}
