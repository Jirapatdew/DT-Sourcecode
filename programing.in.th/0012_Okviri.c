#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void line1(int);
void line2(int);
void line3(int,char []);
int main()
{
    char x[16]={'/0'};
    int len;
    scanf("%s",x);
    len = strlen(x);
    line1(len);
    line2(len);
    line3(len,x);
    line2(len);
    line1(len);
    return 0;
}
void line1(int len)
{
    int i;
    printf(".");
    for(i=1;i<=len;i++)
    {
        if(i%3==0) printf(".*.." );
        else printf(".#..");
    }
    printf("\n");
}
void line2(int len)
{
    int i;
    printf(".");
    for(i=1;i<=len;i++)
    {
        if(i%3==0) printf("*.*.");
        else printf("#.#.");
    }
    printf("\n");
}
void line3(int len,char x[])
{
    int i;
    printf("#");
    for(i=1;i<=len-1;i++)
    {
        if(i%3==0) printf(".%c.*",x[i-1]);
        else if(i%3==2) printf(".%c.*",x[i-1]);
        else printf(".%c.#",x[i-1]);
    }
    if(len%3==0) printf(".%c.*",x[i-1]);
    else printf(".%c.#",x[len-1]);
    printf("\n");
}
