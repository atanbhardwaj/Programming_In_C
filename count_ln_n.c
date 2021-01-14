/*
NAME: ATAN BHARDWAJ
SECTION: ML
ROLL NO.: 31
PROBLEM STATEMENT 10: WRITE A C PROGRAM TO SORT AN ARRAY USING MERGE SORT TECHNIQUE.
*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 100
void ins_arr(int p[max], int l)		//Insert array function array definition
{
    int i;
    printf("Enter elements in the array \n");
    for(i=0;i<l;i++)
        scanf("%d",&p[i]);
}
void merge(int ar[], int i1, int j1, int i2, int j2)		//Merge function definition
{
    int temp[max],i = i1, j = i2, k = 0;
    while((i<=j1)&&(j<=j2))
    {
        if(ar[i]<ar[j])
            temp[k++] = ar[i++];
        else
            temp[k++] = ar[j++];
    }
    while(i<=j1)
    {
        temp[k++] = ar[i++];
    }
    while(j<=j2)
    {
        temp[k++] = ar[j++];
    }
    for(i=i1,j=0;i<=j2;i++,j++)
        ar[i] = temp[j];
}
void m_sort(int a[max],int lb, int ub)		//Merge sort function definition
{
    int mid = 0;
    if(lb<ub)
    {
        mid = (lb+ub)/2;
        m_sort(a,lb,mid);
        m_sort(a,(mid+1),ub);
        merge(a,lb,mid,(mid+1),ub);
    }
}
void disp(int a[max], int n)		//Display function definition
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void main()		//Main function
{
    int c,n,ar[max];
    char ch;
    do
    {
        printf("Enter your choice\nPress 1 to insert elements\nPress 2 to merge sort\nPress 3 to display \n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("Enter the limit of the array \n");
            scanf("%d",&n);
            ins_arr(ar,n);        	//Insert array function call
            break;
        case 2:
            m_sort(ar,0,(n-1));	//Merge sort function call
            break;
        case 3:
            disp(ar,n);		//Display function call
            break;
        }
        printf("Do you want to continue y/n \n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
}
