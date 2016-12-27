#include <stdio.h>
#include <vector>
#include <algorithm>
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
using namespace std;

int dis[200010]={0};
int p[200010]={0};
int T[200010]={0};
int N,K,Q;
vector<int> G[200010];
int DFS(int u,int s,int pa)
{
    p[u]=pa;
    int sz=G[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=G[u][i];
        DFS(v,s+dis[v],pa);
    }
    dis[u]=s;
}
int update(int i,int v)
{
    for(;i<=K;i+=(i&-i)) T[i]+=v;
}
int freqTo(int i)
{
    int sum=0;
    for(;i>0;i-=(i&-i)) sum+=T[i];
    return sum;
}
int main()
{
    int x;
    scanf("%d%d%d",&N,&K,&Q);
    for(int i=1;i<=K;i++)
    {
        scanf("%d",&dis[i]);
        p[i]=i;
    }
    for(int i=K+1;i<=N;i++)
    {
        scanf("%d%d",&x,&dis[i]);
        G[x].push_back(i);
    }
    for(int i=1;i<=K;i++)
    {
        int sz=G[i].size();
        for(int j=0;j<sz;j++)
        {
            int v=G[i][j];
            DFS(v,dis[v],i);
        }
    }
    for(int i=1;i<K;i++) update(i+1,dis[i]);
    for(int i=0;i<Q;i++)
    {
        scanf("%d",&x);
        if(x==0)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a!=K) update(a+1,b-dis[a]);
            dis[a]=b;
        }
        else
        {
            int a,b,c,d,sum=0,tmp=0,tmp2=0;
            scanf("%d%d",&a,&b);
            if(a==b) {printf("0\n");continue;}
            c=p[a];
            d=p[b];
            if(c>d) swap(c,d);
            if(c!=d) tmp=freqTo(d)-freqTo(c);
            tmp2=freqTo(K);
            sum=MIN(tmp,tmp2+dis[K]-tmp);
            if(p[a]!=p[b])
            {
                if(a>K) sum+=dis[a];
                if(b>K) sum+=dis[b];
            }
            else
            {
                if(a<=K) sum+=dis[b];
                else if(b<=K) sum+=dis[a];
                else if(dis[a]>dis[b]) sum+=dis[a]-dis[b];
                else sum+=dis[b]-dis[a];
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
