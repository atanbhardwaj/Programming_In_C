#include <stdio.h>
#include <stdlib.h>
#include<math.h>
// struct node 
// {
//     int info;                    
//     struct node *next;       
// }*p;
// typedef struct node node;
// void create(int n);     
// void main()
// {
//     node *tmp;
//     int n,c = 0;
//     printf(" Input the number of nodes : ");
//     scanf("%d", &n);
//     create(n);
//     tmp = p;
//     while(tmp != NULL)
//     {
//         c++;
//         tmp = tmp->next;
//     }
//     printf("\n Total number of prime nodes = %d\n",c);
// }
// void create(int n)
// {
//     node *f, *tmp;
//     int k, i;
//     p = (node *)malloc(sizeof(node));
//     if(p == NULL)
//     {
//         printf(" Memory can not be allocated.");
//     }
//     else
//     {
//         printf(" Input data for node 1 : ");
//         scanf("%d", &k);
//         p->info =k;      
//         p-> next = NULL;
//         tmp = p;
//         for(i=2; i<=n; i++)
//         {
//             f = (node *)malloc(sizeof(node));
//             if(f == NULL) 
//             {
//                 printf(" Memory can not be allocated.");
//                 break;
//             }
//             else
//             {
//                 printf(" Input data for node %d : ", i);
//                 scanf(" %d", &k);
//                 f->info = k;      
//                 f->next = NULL; 
//                 tmp->next = f; 
//                 tmp = tmp->next;
//             }
//         }
//     }
// } 
struct Node
{
    int info;
    struct Node* next;
}*p;
typedef struct Node node;
void printMiddle(node *);
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
void main()
{
    int n;
    scanf("%d",&n);
    create(n);
    printMiddle(p);
}
/* Function to get the middle of the linked list*/
void printMiddle(node *head)
{
    node *slow_ptr = head;
    node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->info);
    }
}