#include <stdio.h>
#include <stdlib.h>

int map[20][20]={0};

int main()
{
    int r,c;
    int i,j,k;
    scanf("%d%d",&r,&c);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
        {
            scanf("%d",&map[i][j]);
            map[i][j]*=-1;
        }
    map[1][1]=1;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(map[i][j]==-1) continue;
            if(map[i-1][j]!=-1) map[i][j]+=map[i-1][j];
            if(map[i][j-1]!=-1) map[i][j]+=map[i][j-1];
        }
    }
    printf("%d",map[r][c]);
    return 0;
}
