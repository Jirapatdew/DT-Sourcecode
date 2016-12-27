#include <stdio.h>
#include <stdlib.h>

int map[1005][1005]={0};

int val(int x,int y,int k)
{
    return map[x][y]+map[x-k][y-k]-map[x][y-k]-map[x-k][y];
}
int main()
{
    int n,m,a,max=0;
    int k;
    int i,j;
    scanf("%d%d",&n,&m);
    scanf("%d",&k);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) {scanf("%d",&map[i][j]);map[i][j]+=map[i][j-1];}
    for(j=1;j<=m;j++)
        for(i=1;i<=n;i++) map[i][j]+=map[i-1][j];
    for(i=k;i<=n;i++)
    {
        for(j=k;j<=m;j++)
        {
            a=val(i,j,k);
            if(a>max) max=a;
        }
    }
    printf("%d",max);
    return 0;
}
