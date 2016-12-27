#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int len;
    int i,x=0,y=0;
    char c[105];
    gets(c);
    len=strlen(c);
    for(i=0;i<len;i++)
    {
        if(c[i]=='N') y++;
        else if(c[i]=='S') y--;
        else if(c[i]=='E') x++;
        else if(c[i]=='W') x--;
        else if(c[i]=='Z') {y=0;x=0;}
    }
    printf("%d %d",x,y);
    return 0;
}
