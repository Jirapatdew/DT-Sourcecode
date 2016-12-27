#include <stdio.h>
#include <stdlib.h>


int mapwater[60][60]= {0};
char map[60][60]= {'\0'};
int chk[60][60]= {0};
int r,c,t=0;
int min=99999;
int water(int x,int y,int cnt)
{
    if(x<0||y<0||x>=r||y>=c) return 0;
    if(map[x][y]!='X'&&map[x][y]!='D'&&mapwater[x][y]>cnt)
    {
        mapwater[x][y]=cnt;
        //printf("%d     %d      %d\n",x,y,cnt);
        water(x+1,y,cnt+1);
        water(x,y+1,cnt+1);
        water(x-1,y,cnt+1);
        water(x,y-1,cnt+1);
    }
}
int distance(int x,int y,int cnt)
{
    if(chk[x][y]>cnt||chk[x][y]==-1) chk[x][y]=cnt;
    else return 0;
    if(x<0||y<0||x>=r||y>=c) return 0;
    if(mapwater[x][y]<=cnt) return 0;
    if(map[x][y]=='D')
    {
        if(min>cnt) min=cnt;
        t=1;
        return 0;
    }
    else if(map[x][y]!='X')
    {
        //printf("%d %d %d\n",x,y,cnt);
        distance(x+1,y,cnt+1);
        distance(x,y+1,cnt+1);
        distance(x-1,y,cnt+1);
        distance(x,y-1,cnt+1);

    }
}
int main()
{
    int i,j,si=0,sj=0;
    scanf("%d%d",&r,&c);
    for(i=0; i<r; i++) scanf("%s",map[i]);
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
        {
            mapwater[i][j]=99999;
            chk[i][j]=-1;
        }
    for(i=0; i<r; i++)//หาว่าน้ำจะไปถึงจุดนั้นเร็วสุดเท่าไหร่
    {
        for(j=0; j<c; j++)
        {
            if(map[i][j]=='*')
            {
                water(i,j,0);
            }
            else if(map[i][j]=='S')
            {
                si=i;
                sj=j;
            }
        }
    }
    distance(si,sj,0);
    if(t==1) printf("%d",min);
    else printf("KAKTUS");
    return 0;
}
