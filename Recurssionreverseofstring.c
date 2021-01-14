#include<stdio.h>
void rev(char *s)
{
    if(s!='\0')
    {
        rev(s+1);
    }
    printf("%c",s);
    return;
}
void main()
{
    char str[30];
    printf("Enter the string \n");
    gets(str);
    rev(str);
}