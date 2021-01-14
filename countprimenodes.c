#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct node 
{
    int info;                    
    struct node *next;       
}*p;
typedef struct node node;
void create(int n);     
void main()
{
    node *tmp;
    int n,c,i,pr=0,k;
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    create(n);
    tmp = p;
    while(tmp != NULL)
    {
        k=tmp->info;
        c=0;
        for(i=2;i<=sqrt(k);i++)
        {
            
            if((k)%i==0)
            {
                c=1;
                break;
            }
        }
        if(c==0)
        {
            pr++;
        }
        tmp = tmp->next;
    }
    printf("\n Total number of prime nodes = %d\n",pr);
}
void create(int n)
{
    node *f, *tmp;
    int k, i;
    p = (node *)malloc(sizeof(node));
    if(p == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        printf(" Input data for node 1 : ");
        scanf("%d", &k);
        p->info =k;      
        p-> next = NULL;
        tmp = p;
        for(i=2; i<=n; i++)
        {
            f = (node *)malloc(sizeof(node));
            if(f == NULL) 
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &k);
                f->info = k;      
                f->next = NULL; 
                tmp->next = f; 
                tmp = tmp->next;
            }
        }
    }
} 
