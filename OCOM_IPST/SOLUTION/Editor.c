#include <stdio.h>
#include <stdlib.h>

char s[100005][20]= {'\0'};
int a[100005],b[100005];
int c=0,d=1;

void insert()
{
    scanf("%s",s[d]);
    a[d]=a[c];
    b[a[c]]=d;
    b[d]=c;
    a[c]=d;
    c=d;
    d++;
}
void left()
{
    if(b[c]>=0) c=b[c];
}
void right()
{
    if(a[c]>=0) c=a[c];
}
void backspace()
{
    if(c>0)
    {
        a[b[c]]=a[c];
        if(a[c]>=0) b[a[c]]=b[c];
        c=b[c];
    }
}
void del()
{
    if(a[c]>=0)
    {
        right();
        backspace();
    }
}
int main()
{
    int n,i;
    char x;
    a[0]=-1;
    b[0]=-1;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf(" %c",&x);
        if(x=='i') insert();
        else if(x=='l') left();
        else if(x=='r') right();
        else if(x=='b') backspace();
        else if(x=='d') del();
    }
    i=a[0];
    while(i>=0)
    {
        printf("%s ",s[i]);
        i=a[i];
    }
    return 0;
}
