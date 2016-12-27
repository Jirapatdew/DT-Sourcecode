#include <stdio.h>
#include <queue>
#define INF 20000000
#define MIN(_x,_y) (_x<_y)?_x:_y
#define MAX(_x,_y) (_x>_y)?_x:_y
using namespace std;

// n^2
int a[2505][2505]={0},n;
int chk[2505][2505][4]={0};
char c[2505][2505];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<int> qx,qy;

int add(int x,int y,int val)
{
    a[x][y]=val;
    qx.push(x);qy.push(y);
}
int walk(int x,int y,int val)
{
    for(int i=x-1;i>=1;i--)
    {
        if(c[i][y]=='#') break;
        if(chk[i][y][3]==1) break;
        chk[i][y][3]=1;
        if(a[i][y]==INF) add(i,y,val);
    }
    for(int i=x+1;i<=n;i++)
    {
        if(c[i][y]=='#') break;
        if(chk[i][y][2]==1) break;
        chk[i][y][2]=1;
        if(a[i][y]==INF) add(i,y,val);
    }
    for(int i=y-1;i>=1;i--)
    {
        if(c[x][i]=='#') break;
        if(chk[x][i][1]==1) break;
        chk[x][i][1]=1;
        if(a[x][i]==INF) add(x,i,val);
    }
    for(int i=y+1;i<=n;i++)
    {
        if(c[x][i]=='#') break;
        if(chk[x][i][0]==1) break;
        chk[x][i][0]=1;
        if(a[x][i]==INF) add(x,i,val);
    }
}
int main()
{
    int mx=0,num=0;
    int x,y;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++) gets(c[i]+1);
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++) a[i][j]=INF;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(c[i][j]=='K') {x=i;y=j;i=n;break;}
    a[x][y]=0;
    chk[x][y][0]=chk[x][y][1]=chk[x][y][2]=chk[x][y][3]=1;
    walk(x,y,0);
    while(!qx.empty())
    {
            x=qx.front();qx.pop();
            y=qy.front();qy.pop();
            if(x<1||y<1||x>n||y>n) continue;
            walk(x,y,a[x][y]+1);
    }
//for(int i=1;i<=n;i++)
  //      {for(int j=1;j<=n;j++) if(a[i][j]!=INF)printf("%d ",a[i][j]);else printf("# "); printf("\n");}
   for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]!=INF)
            {
                if(mx==a[i][j]) num++;
                else if(mx<a[i][j])
                {
                    mx=a[i][j];
                    num=1;
                }
            }
    printf("%d\n%d",mx,num);

    return 0;
}
