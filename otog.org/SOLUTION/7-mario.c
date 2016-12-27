#include <stdio.h>
#include <stdlib.h>

int map[505][505]={0};
int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}
int main()
{
    int n,m;
    int x,y,ans;
    int i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++) scanf("%d",&map[i][j]);
    for(i=2;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            x=map[i-1][j];
            if(j-1>=1) x=min(x,map[i-1][j-1]);
            if(j+1<=n) x=min(x,map[i-1][j+1]);
            map[i][j]+=x;
        }
    }
    ans=map[m][1];
    for(j=2;j<=n;j++) ans=min(ans,map[m][j]);
    printf("%d\n",ans);
    return 0;
}
