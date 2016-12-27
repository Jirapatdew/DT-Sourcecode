#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct node
{
    int p;
    int t;
};
vector<node> G[100005];
int visit[100005];
int pass,key;
int n,m,dt=0;

int BPT(int u,int color)
{
    int i,s=G[u].size(),child;
    visit[u]=color;
    if(pass==1) return 0;
    for(i=0;i<s;i++)
    {
        if(G[u][i].t>key) continue;
        child=G[u][i].p;
        if(visit[child]==-1) BPT(child,(color+1)%2);
        else if(visit[child]==color) pass=1;
    }
}
int binary(int low,int high)
{
    int mid=(low+high)/2,chk;
    int i;
    if(low<=high)
    {
        key=mid;
        pass=0;
        for(i=1;i<=n;i++) visit[i]=-1;
        for(i=1;i<=n;i++) if(visit[i]==-1) BPT(i,0);
        if(pass==1)
        {
            dt=mid;
            binary(low,mid-1);
        }
        else
        {
            binary(mid+1,high);
        }
    }
}
int main()
{
    node a,b;
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a.p,&b.p);
        a.t=b.t=i;
        G[a.p].push_back(b);
        G[b.p].push_back(a);
    }
    binary(1,m);
    printf("%d",dt-1);
    return 0;
}
