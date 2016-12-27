#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int right(int a,int b)
{
    while(a!=b)
    {
        printf("R");
        a++;
        a%=4;
    }
}
int main()
{
    int len;
    int i,t=0;
    char c[105];
    gets(c);
    len=strlen(c);
    for(i=0;i<len;i++)
    {
        if(c[i]=='N')
        {
            if(t!=0) right(t,0);
            t=0;
            printf("F");
        }
        else if(c[i]=='E')
        {
            if(t!=1) right(t,1);
            t=1;
            printf("F");
        }
        else if(c[i]=='S')
        {
            if(t!=2) right(t,2);
            t=2;
            printf("F");
        }
        else if(c[i]=='W')
        {
            if(t!=3) right(t,3);
            t=3;
            printf("F");
        }
        else if(c[i]=='Z') {t=0;printf("Z");}
    }
    return 0;
}
