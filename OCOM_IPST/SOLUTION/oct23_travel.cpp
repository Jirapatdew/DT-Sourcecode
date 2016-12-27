#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[30010];
queue<int> Q;
int main()
{
    int n,m,u,v;
    int dis[30010]={0};
    int p[30010]={0};
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int s=1,sz,t,sum=0,tmp;

    srand(time(NULL));
    s=rand()%n+1;
    Q.push(s);
    dis[s]=0;
    p[s]=0;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        sz=G[u].size();
        for(int j=0;j<sz;j++)
        {
            v=G[u][j];
            if(v!=p[u])
            {
                Q.push(v);
                dis[v]=dis[u]+1;
                p[v]=u;
            }
        }
    }
    s=1;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&t);
        tmp=t;
        while(s!=t)
        {
            if(dis[s]>dis[t]) {sum++;s=p[s];}
            else if(dis[t]>dis[s]) {sum++;t=p[t];}
            else
            {
                s=p[s];
                t=p[t];
                sum+=2;
            }
        }
        s=tmp;
    }
    printf("%d",sum);
    return 0;
}
