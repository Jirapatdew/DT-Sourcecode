#include <stdio.h>
#include <stdlib.h>

int xa,ya,map[200][200]= {0},l,til[1000][5],d=0,a,b,p=0;
int tiling(int x,int y)
{
    if(y==l&&x<l) {x++;y=0;}
    else if(x==l&&p==0)
    {
        p=1;
        for(a=0;a<d;a++)
        {
            for(b=0;b<3;b++) printf("%d ",til[a][b]);
            printf("\n");
        }

    }
    if(map[x][y]==0&&p==0)
    {
        if(map[x+1][y]==0&&map[x+1][y+1]==0&&p==0)
        {
            map[x][y]=1;map[x+1][y]=1;map[x+1][y+1]=1;
            til[d][0]=1;til[d][1]=y;til[d][2]=x;
            d++;
            tiling(x,y+1);
            d--;
            map[x][y]=0;map[x+1][y]=0;map[x+1][y+1]=0;
        }
        if(map[x][y+1]==0&&map[x+1][y+1]==0&&p==0)
        {
            map[x][y]=1;map[x][y+1]=1;map[x+1][y+1]=1;
            til[d][0]=2;til[d][1]=y;til[d][2]=x;
            d++;
            tiling(x,y+1);
            d--;
            map[x][y]=0;map[x][y+1]=0;map[x+1][y+1]=0;
        }
        if(map[x][y+1]==0&&map[x+1][y]==0&&p==0)
        {
            map[x][y]=1;map[x][y+1]=1;map[x+1][y]=1;
            til[d][0]=3;til[d][1]=y;til[d][2]=x;
            d++;
            tiling(x,y+1);
            d--;
            map[x][y]=0;map[x][y+1]=0;map[x+1][y]=0;
        }

    }
    else if(map[x][y]==1&&p==0)
    {
        if(map[x][y+1]==0&&map[x+1][y+1]==0&&map[x+1][y]==0&&p==0)
        {
            map[x][y+1]=1;map[x+1][y+1]=1;map[x+1][y]=1;
            til[d][0]=0;
            til[d][1]=y;
            til[d][2]=x;
            d++;
            tiling(x,y+1);
            d--;
            map[x][y+1]=0;map[x+1][y+1]=0;map[x+1][y]=0;
        }
    }
    if(p==0) tiling(x,y+1);
}
int main()
{
    int i,j;
    scanf("%d%d%d",&l,&xa,&ya);
    map[ya][xa]=2;
    tiling(0,0);
    return 0;
}
