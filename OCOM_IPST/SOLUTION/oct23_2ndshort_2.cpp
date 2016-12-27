#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#define MAXINT 1000000000
using namespace std;


struct edge
{
    int p;// point to next node
    int w;//weight of edge
    edge(int x,int y)
    {
        p=x;
        w=y;
    }
};
struct node
{
    int d;//distant of node
    int idx;//index of node
    bool operator < (const node &T) const
    {
         if(d != T.d) return d < T.d;
         else return idx < T.idx;
    }
    node(int x,int y)
    {
        d=x;
        idx=y;
    }
};


vector<edge> G[10005];
vector<int> D (10005,MAXINT);
vector<edge> G2[10005];
vector<int> D2 (10005,MAXINT),asdf;
set<node> Q;
set<node>::iterator it;
int main()
{
    int n,m,s,t;//n = Number of vertex. m = Number of edges.
    int i;    //s = source  t = node that you find shortest path
    int u,v,l,min=MAXINT;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&l);
        G[u].push_back(edge(v,l));
        G2[v].push_back(edge(u,l));
    }
    /*------------------------------------------------------------------------------*/
    D[s]=0;
    Q.insert(node(D[s],s));
    while(!Q.empty())
    {
        u=Q.begin()->idx;
        Q.erase(Q.begin());
        for(i=0;i<G[u].size();i++)
        {
            v=G[u][i].p;
            l=G[u][i].w;
            if(D[v]>D[u]+l)
            {
                if(D[v] != MAXINT) Q.erase(Q.find(node(D[v],v)));
                D[v]=D[u]+l;
                Q.insert(node(D[v],v));
            }
        }
    }
    /*------------------------------------------------------------------------------*/
    D2[t]=0;
    Q.insert(node(D2[t],t));
    while(!Q.empty())
    {
        u=Q.begin()->idx;
        Q.erase(Q.begin());
        for(i=0;i<G2[u].size();i++)
        {
            v=G2[u][i].p;
            l=G2[u][i].w;
            if(D2[v]>D2[u]+l)
            {
                if(D2[v] != MAXINT) Q.erase(Q.find(node(D2[v],v)));
                D2[v]=D2[u]+l;
                Q.insert(node(D2[v],v));
            }
        }
    }
    /*------------------------------------------------------------------------------*/
    for(i=1;i<=n;i++)
    {
        if(min>D[i]+D2[i]&&D[i]+D2[i]!=D[t]) min=D[i]+D2[i];
    }
    printf("%d",min);
    return 0;
}
