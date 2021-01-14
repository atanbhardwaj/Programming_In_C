#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node node;
node *insert(node *,int);
node *serve(node *);
void  disp(node *);
void main()
{
    node *front=NULL, *rear=NULL;
    int n,num;
    char ch;
    do
    {
        printf("Press 1 to Insert\nPress 2 to serve\nPress 3 to display\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
                printf("Enter the element to insert\n");
                scanf("%d",&num);
                rear = insert(rear,num);
                if(front==NULL)
                    front = rear;
                break;
            }
            case 2:
            {
                if(front==NULL)
                    printf("Queue is Empty\n");
                else
                {
                    front  = serve(front);
                    rear = front;
                }
                break;
            }
            case 3:
            {
                if(front == NULL)
                    printf("Queue is Empty\n");
                else
                    disp(front);
                break;
            }   
        }
    printf("Do you want to continue y/n?\n");
    fflush(stdin);
    scanf("%c",&ch);
    }while(ch=='y');
}
node *insert(node *rr,int n)
{
    node *p;
    p = (node*)malloc(sizeof(node));
    if(p==NULL)
        printf("Not Enough Memory Available\n");
    else
    {
        p->info=n;
        p->next=rr;
        if(rr==NULL)
            rr=p;
        else
        {
            (rr)->next=p;
            rr=p;
        }
    }
    return(rr);
}
node *serve(node *ft)
{
    node *temp;
    temp = ft;
    printf("Element served is %d\n",((ft)->info));
    ft = (ft)->next;
    free(temp);
    return(ft);
}
void disp(node *ft)
{
    while(ft!=NULL)
    {
        printf("%d\n",((ft)->info));
        ft = (ft)->next;
    }
}
