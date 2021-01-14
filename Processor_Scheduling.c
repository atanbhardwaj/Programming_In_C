#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
 int info;
 int num;
 struct node* next;
} node;
node* push(int i)
{
 node *p=(node*)malloc(sizeof(node));
 if(p==NULL)
 printf("Not enough memory\n");
 else
 {
 scanf("%d",&(p->info));
 p->num=i;
 return(p);
 }
}
void cal_time(node *f,node *r,int n)
{
 node *temp=f;
 int c=0,row=1;
 while(n!=0){
 temp->info=(temp->info)-10;
 c++;
 if(c%n==0&&c!=n)
 row++;
 if(temp->info<=0)
 {
 n--;
 printf("Program %d executed\n",temp->num);
 printf("finishing time : %d\n",(c*10));
 printf("waiting time: %d\n",((c*10)-(row*10)));
 while(f->next!=temp)
 {
 f=f->next;
 }
 f->next=temp->next;
 free(temp);
 }
 temp=temp->next;
 }
}
void main()
{
 int n,num,i=1;
 node *f=NULL,*r=NULL;
 printf("\t\t****INPUT****\n");
 printf("Enter the number of programs:");scanf("%d",&n);
 num=n;
 while(n!=0)
 {
 printf("Enter the execution time of program %d:",i);
 if(f==NULL)
 {
 r=push(i);
 f=r;
 }
 else
 {
 r->next=push(i);
 r=r->next;
 }
 r->next=f;
 n--;
 i++;
 }
 printf("\t\t****OUTPUT****\n");
  cal_time(f,r,num);
 getch();
}
