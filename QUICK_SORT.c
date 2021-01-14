/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 11: WRITE A C PROGRAM TO SORT AN ARRAY USING QUICK SORT TECHNIQUE.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 100
void ins_arr(int p[max], int l)
{
    int i;
    printf("Enter elements in the array \n");
    for(i=0;i<l;i++)
        scanf("%d",&p[i]);
}
void quick_sort(int a[max], int lb, int ub)
{
    int i=lb, j=ub, key = a[lb], t=0;
    if(lb>=ub)
        return;
    while(i<j)
    {
        while(key>=a[i]&&i<j)
        {
            i++;
        }
        while(key<a[j])
        {
            j--;
        }
        if(i<j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[lb] = a[j];
    a[j] = key;
    quick_sort(a,lb,(j-1));
    quick_sort(a,(j+1),ub);
}
void disp(int a[max], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void main()
{
    int c,n,ar[max];
    char ch;
    do
    {
        printf("Enter your choice\nPress 1 to insert elements\nPress 2 to quick sort\nPress 3 to display \n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("Enter the limit of the array \n");
            scanf("%d",&n);
            ins_arr(ar,n);
            break;
        case 2:
            quick_sort(ar,0,(n-1));
            break;
        case 3:
            disp(ar,n);
            break;
        }
        printf("Do you want to continue y/n \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
}

