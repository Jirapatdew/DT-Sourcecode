/*
TASK: car
LANG: C
AUTHOR: Jirapat Atiwattanachai
CENTER: KKU03
*/
#include <stdio.h>
#include <stdlib.h>

int map[110][45]= {0};
int ans[110]= {0};
int m,t,d;

int len(int st,int sl)
{
    if(st==t)
    {
        for(d=0;d<t;d++) printf("%d\n",ans[d]);
    }
    else
    {
        if(map[st+1][sl-1]==0&&(sl-1)>0)
        {
            ans[st]=1;
            len(st+1,sl-1);
        }
        if(map[st+1][sl+1]==0&&(sl+1)<=m)
        {
            ans[st]=2;
            len(st+1,sl+1);
        }
        if(map[st+1][sl]==0&&(st+1)<=t)
        {
            ans[st]=3;
            len(st+1,sl);
        }
    }
}
int main()
{
    int n,i,j;
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    len(0,n);
    return 0;
}
