#include <stdio.h>
#include <stdlib.h>

int map[1005][1005]={0};
int main()
{
    int n,m,k,q;
    int i,j;
    int x,y,X,Y;
    scanf("%d%d",&m,&n);
    scanf("%d",&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d%d%d%d",&x,&y,&X,&Y);
        map[y][x]++;
        map[Y+1][X+1]++;
        map[y][X+1]--;
        map[Y+1][x]--;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            map[i][j]+=map[i][j-1];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            map[j][i]+=map[j-1][i];
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",map[y][x]%2);
    }
    return 0;
}
