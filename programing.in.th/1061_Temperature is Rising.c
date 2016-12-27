#include <stdio.h>
#include <stdlib.h>

int map[22][22]={0},m,max=-5;
int dt(int x,int y)
{
    max=(max<map[x][y])?map[x][y]:max;
    if(x<m&&map[x+1][y]!=100&&map[x+1][y]>map[x][y]) dt(x+1,y);
    if(y<m&&map[x][y+1]!=100&&map[x][y+1]>map[x][y]) dt(x,y+1);
    if(x-1>0&&map[x-1][y]!=100&&map[x-1][y]>map[x][y]) dt(x-1,y);
    if(y-1>0&&map[x][y-1]!=100&&map[x][y-1]>map[x][y]) dt(x,y-1);
    return 0;
}
int main()
{
    int x,y,i,j;
    scanf("%d",&m);
    scanf("%d%d",&x,&y);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    dt(y,x);
    printf("%d",max);
    return 0;
}
