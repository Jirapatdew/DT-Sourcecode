#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[1005];
int len,x=0;
void pr(int p)
{
    if(x>p) return 0;
    else
    {
        printf("%c",a[p]);
        pr(p-1);
    }
}
int wordrev(int p)
{
    if(p==len)
    {
        pr(p-1);
        return 0;
    }
    else
    {
        if(a[p]=='_') {pr(p-1);x=++p;printf("_");wordrev(p+1);}
        else wordrev(p+1);
    }
}
int main()
{
    scanf("%s",a);
    len=strlen(a);
    wordrev(0);
    return 0;
}
