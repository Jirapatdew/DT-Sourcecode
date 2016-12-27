#include <stdio.h>
#include <vector>
#include <queue>
#define INF (-1u/2)
using namespace std;

struct dt
{
    int u,w;
    bool operator <(const dt& T) const {return w>T.w;}
    dt(int _u,int _w) {u=_u;w=_w;}
};
vector<int> G[50010],W[50010],D[50010];
priority_queue<dt> H;
int dis[50010]={0};
int inT[50010]={0};
int STP(int s,int t,int day)
{
    for(int i=s;i<=t;i++) dis[i]=INF;
    dis[s]=0;
    H.push(dt(s,0));
    while(!H.empty())
    {
        int u=H.top().u,tmp=H.top().w;
        H.pop();
        if(dis[u]!=tmp) continue;
        int sz=G[u].size(),v;
        for(int i=0;i<sz;i++)
        {
            if(D[u][i]>day) break;
            v=G[u][i];
            if(dis[u]+W[u][i]<dis[v])
            {
                dis[v]=dis[u]+W[u][i];
                H.push(dt(v,dis[v]));
            }
        }
    }
}
int main()
{
    int n,m,k,u,v,w;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back(v);
        G[v].push_back(u);
        W[u].push_back(w);
        W[v].push_back(w);
        D[u].push_back(i);
        D[v].push_back(i);
    }
    int l=1,r=m,ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        STP(1,n,mid);
        if(dis[n]<=k)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%d",ans);
    return 0;
}
