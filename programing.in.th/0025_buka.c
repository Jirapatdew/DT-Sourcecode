#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[101],b[101],op;
    int na,nb,i,x;
    scanf("%s\n%c\n%s",a,&op,b);
    na=strlen(a);
    nb=strlen(b);
    if(op=='*')
    {
        printf("%s",a);
        for(i=1;i<nb;i++) printf("%c",b[i]);
    }
    if(op=='+')
    {
        if(na>nb)
        {
            x=na-nb;
            a[x]='1';
            printf("%s",a);
        }
        else if(na<nb)
        {
            x=nb-na;
            b[x]='1';
            printf("%s",b);
        }
        else
        {
            a[0]='2';
            printf("%s",a);
        }
    }
    return 0;
}
