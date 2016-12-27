#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,x,y,r,i,j,k,total,a,b,c,d;
    int map[1005][1005]={0};
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) {scanf("%d%d",&x,&y);map[y][x]=1;}
    for(k=0;k<m;k++)
    {
        scanf("%d%d%d",&x,&y,&r);
        total=0;
        if(y-r>=0) a=y-r; else a=0;
        if(y+r<=1000) b=y+r; else b=1000;
        if(x-r>=0) c=x-r; else c=0;
        if(x+r<=1000) d=x+r; else d=1000;
        for(i=a;i<=b;i++)
        {
            for(j=c;j<=d;j++)
            {
                if(map[i][j]==1) {map[i][j]=0;total++;}
            }
        }
        printf("%d\n",total);
    }
    return 0;
}
