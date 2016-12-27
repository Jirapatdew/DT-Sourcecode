#include <stdio.h>
#include <vector>
#define MAX(_x,_y) ((_x>_y)?_x:_y)
using namespace std;

vector<int> G[1010];
int val[1010][3]={0};

int DFS(int u,int p)
{
    int sz=G[u].size(),v;
    if(sz==1&&p!=0) {val[u][1]++;return 0;}
    for(int i=0;i<sz;i++)
    {
        v=G[u][i];
        if(v!=p) DFS(v,u);
    }
    int tmp[3],mx=0;
    val[u][1]=1;
    for(int i=0;i<sz;i++)
    {
        v=G[u][i];
        if(v!=p)
        {
            val[u][0]+=MAX(val[v][0],MAX(val[v][1],val[v][2]));
            val[u][1]+=val[v][0];
            mx=MAX(mx,val[v][1]);
        }
    }
    if(mx!=0) val[u][2]=mx+1;
}
int main()
{
    int n,c;
    scanf("%d",&c);
    while(c>0)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
        {
            G[i].clear();
            val[i][0]=val[i][1]=val[i][2]=0;
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        DFS(1,0);
        printf("%d\n",MAX(val[1][0],MAX(val[1][1],val[1][2])));
        c--;
    }
    return 0;
}
