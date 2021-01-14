/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 9: WRITE A C PROGRAM TO SORT AN ARRAY USING INSERTION SORT TECHNIQUE.
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
void ins_sort(int a[max], int n)
{
    int i,j,t;
    for(i = 1; i<n; i++)
    {
        t = a[i];
        j = i-1;
        while(j>=0&&t<a[j])
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = t;
    }
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
        printf("Enter your choice\nPress 1 to insert elements\nPress 2 to sort\nPress 3 to display \n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("Enter the limit of the array \n");
            scanf("%d",&n);
            ins_arr(ar,n);
            break;
        case 2:
            ins_sort(ar,n);
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
