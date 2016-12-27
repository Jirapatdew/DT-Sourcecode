#include <stdio.h>
#include <vector>
#include <queue>
#define INF (-1u/4)
using namespace std;

vector<int> G[100010],W[100010];
int d[100010]={0};
int chk[100010]={0};
struct dt
{
    int u,dis;
    bool operator <(const dt& T) const
    {
        return dis>T.dis;
    }
    dt(int _u,int _dis)
    {
        u=_u;
        dis=_dis;
    }
};
priority_queue<dt> H;

int main()
{
    int n,m,s,t;//n==node m=edge
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=n;i++) d[i]=INF;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(v);
        W[u].push_back(w);
    }
    H.push(dt(s,0));
    d[s]=0;
    while(!H.empty())
    {
        int u=H.top().u;
        H.pop();
        if(chk[u]==1) continue;
        chk[u]=1;
        int sz=G[u].size();
        for(int i=0;i<sz;i++)
        {
            int v=G[u][i],w=W[u][i];
            if(chk[v]==1) continue;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                H.push(dt(v,d[v]));
            }
        }
    }
    if(d[t]!=INF) printf("%d",d[t]);
    else printf("-1");
    return 0;
}
