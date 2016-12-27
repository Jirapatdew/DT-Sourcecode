/*
TASK: pipe.cpp
LANG: C++
COMPILER: WCB
AUTHOR: Jirapat Atiwattanachai
ID: KKU07
*/
#include <stdio.h>

using namespace std;

int map[350][350]={0},num=0;
int ans[2000]={0};
int walk(int x,int y,int p)
{
    ans[num]++;
    if(map[x][y]==11)
    {
        map[x][y]=0;
        if(p==1) walk(x,y-1,2);
        else walk(x-1,y,3);
    }
    else if(map[x][y]==12)
    {
        map[x][y]=0;
        if(p==1) walk(x,y+1,4);
        else walk(x-1,y,3);
    }
    else if(map[x][y]==13)
    {
        map[x][y]=0;
        if(p==4) walk(x+1,y,1);
        else walk(x,y-1,2);
    }
    else if(map[x][y]==14)
    {
        map[x][y]=0;
        if(p==2) walk(x+1,y,1);
        else walk(x,y+1,4);
    }
    else if(map[x][y]==21)
    {
        map[x][y]=0;
        if(p==1) walk(x+1,y,1);
        else walk(x-1,y,3);
    }
    else if(map[x][y]==22)
    {
        map[x][y]=0;
        if(p==2) walk(x,y-1,2);
        else walk(x,y+1,4);
    }
    else if(map[x][y]==31)
    {
        if(p==1) {map[x][y]=22;walk(x+1,y,1);}
        else if(p==3) {map[x][y]=22;walk(x-1,y,3);}
        else if(p==2) {map[x][y]=21;walk(x,y-1,2);}
        else {map[x][y]=21;walk(x,y+1,4);}
    }
    else ans[num]--;
    return 0;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&map[i][j]);
    for(int j=1;j<=m;j++)
    {
        if(map[1][j]==11||map[1][j]==12||map[1][j]==21||map[1][j]==31)
        {num++;walk(1,j,1);}
    }
    for(int j=1;j<=m;j++)
    {
        if(map[n][j]==13||map[n][j]==14||map[n][j]==21||map[n][j]==31)
        {num++;walk(n,j,3);}
    }
    for(int i=1;i<=n;i++)
    {
        if(map[i][1]==11||map[i][1]==13||map[i][1]==22||map[i][1]==31)
        {num++;walk(i,1,4);}
    }
    for(int i=1;i<=n;i++)
    {
        if(map[i][m]==12||map[i][m]==14||map[i][m]==22||map[i][m]==31)
        {num++;walk(i,m,2);}
    }
    printf("%d\n",num);
    for(int i=1;i<=num;i++) printf("%d ",ans[i]);

    return 0;
}
