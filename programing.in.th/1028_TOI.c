#include <stdio.h>
#include <stdlib.h>

int var[30]={0};
void Value()
{
    char ch;
    int x;
    scanf(" %c %d",&ch,&x);
    var[ch-'A']=x;
}
void op(char p)
{
    char x;
    char y;
    scanf(" %c %c",&x,&y);
    if(p=='+') {var[x-'A']+=var[y-'A'];}
    else if(p=='-') {var[x-'A']-=var[y-'A'];}
    else if(p=='*') {var[x-'A']*=var[y-'A'];}
    else if(p=='/') {var[x-'A']/=var[y-'A'];}
}
int main()
{
    char ch,p;
    while(1)
    {
        scanf("%c",&ch);
        if(ch=='\n') scanf("%c",&ch);
        if(ch=='=') Value();
        else if(ch=='#') {scanf(" %c",&p);printf("%d\n",var[p-'A']);}
        else if(ch=='!') break;
        else op(ch);
    }
    printf("!");
    return 0;
}
