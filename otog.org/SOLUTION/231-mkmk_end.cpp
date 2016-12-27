#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

char a[1005][1005]={'\0'};
int chk[1005][1005]={0};
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

queue<int> qx,qy;
stack<int> sx,sy;
int bfs(int x,int y)
{
    printf("1 %d %d\n",x,y);
    qx.push(x);qy.push(y);
    chk[x][y]=1;
    while(!qx.empty())
    {
        x=qx.front();qx.pop();
        y=qy.front();qy.pop();
        if(chk[x][y]!=1) {sx.push(x);sy.push(y);}
        for(int i=0;i<4;i++)
        {
            if(chk[x+dx[i]][y+dy[i]]==0&&a[x+dx[i]][y+dy[i]]=='.')
            {
                printf("1 %d %d\n",x+dx[i],y+dy[i]);
                qx.push(x+dx[i]);qy.push(y+dy[i]);
                chk[x+dx[i]][y+dy[i]]=chk[x][y]+1;
            }
        }
    }
    while(!sx.empty())
    {
        printf("3 %d %d\n",sx.top(),sy.top());
        printf("2 %d %d\n",sx.top(),sy.top());
        sx.pop(),sy.pop();
    }
}
int main()
{
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++) gets(a[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if(a[i][j]=='.'&&chk[i][j]==0) bfs(i,j);
    printf("0");
    return 0;
}
