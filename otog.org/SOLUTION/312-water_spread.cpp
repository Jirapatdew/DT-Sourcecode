#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int a[1005][1005]={0},n;
int ans[1000005]={0};
queue<pair <int,int> > Q;
int flow(pair <int,int> P)
{
    int x= P.first;
    int y= P.second;
    int t= a[x][y];
    if(x<1||y<1||x>n||y>n) return 0;
    ans[t-1]++;
    if(a[x-1][y]==0) Q.push(make_pair(x-1,y));
    if(a[x+1][y]==0) Q.push(make_pair(x+1,y));
    if(a[x][y-1]==0) Q.push(make_pair(x,y-1));
    if(a[x][y+1]==0) Q.push(make_pair(x,y+1));
    a[x-1][y]=t+1;
    a[x+1][y]=t+1;
    a[x][y-1]=t+1;
    a[x][y+1]=t+1;
    return 0;
}
int main()
{
    int m,q;
    int x,y;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        a[x][y]=-1;
    }
    scanf("%d%d",&x,&y);
    a[x][y]=1;
    Q.push(make_pair(x,y));
    while(!Q.empty())
    {
        flow(Q.front());
        Q.pop();
    }
    for(int i=1;i<=n*n;i++) ans[i]+=ans[i-1];
    for(int i=0;i<q;i++)
    {
        scanf("%d",&x);
        printf("%d\n",ans[x]);
    }
    return 0;
}
