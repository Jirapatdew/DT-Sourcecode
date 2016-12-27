#include <stdio.h>
#include <stdlib.h>

int x,y,d=0;
char map[40][40]= {'\0'};

int check(int n,int p)
{
    if(n==x-1)
    {
        d=1;
        return 0;
    }
    else
    {
        if(p>0&&map[n][p-1]=='.'&&map[n-1][p-1]=='.')
        {
            map[n][p+1]='#';map[n-1][p+1]='#';
            check(n,p-1);
            map[n][p+1]='.';map[n-1][p+1]='.';
        }
        if(p<y-1&&map[n][p+2]=='.'&&map[n-1][p+2]=='.')
        {
            map[n][p]='#';map[n-1][p]='#';
            check(n,p+1);
            map[n][p]='.';map[n-1][p]='.';
        }
        if(map[n+1][p]=='.'&&map[n+1][p+1]=='.')
        {
            map[n-1][p]='#';map[n-1][p+1]='#';
            check(n+1,p);
            map[n-1][p]='.';map[n-1][p+1]='.';
        }
        if(n>1&&map[n-2][p]=='.'&&map[n-2][p+1]=='.')
        {
            map[n][p]='#';map[n][p+1]='#';
            check(n-1,p);
            map[n][p]='.';map[n][p+1]='.';
        }
        return 0;
    }
}
int main()
{
    int i;
    scanf("%d%d",&x,&y);
    for(i=0; i<x; i++) scanf("%s",map[i]);
    for(i=0; i<y-1; i++)
    {
        if(map[0][i]=='.'&&map[0][i+1]=='.'&&map[1][i]=='.'&&map[1][i+1]=='.')
        {
            if(x==2) d=1;
            else check(1,i);
        }
    }
    if(d==1) printf("yes");
    else printf("no");
    return 0;
}
