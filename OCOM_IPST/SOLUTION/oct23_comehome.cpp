#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#define MAXINT 2000000000
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


vector<edge> G[105];
vector<int> D (105,MAXINT);
set<node> Q;
set<node>::iterator it;
int main()
{
    int s;//n = Number of vertex. m = Number of edges.
    int i;
    char a[5],b[5];    //s = source  t = node that you find shortest path
    int u,v,l,min=MAXINT,id=0;
    int P;
    scanf("%d",&P);
    s=52;
    for(i=1;i<=P;i++)
    {
        scanf("%s%s%d",a,b,&l);
        u=(a[0]>='a'&&a[0]<='z')?(a[0]-'a'+1):(a[0]-'A'+27);
        v=(b[0]>='a'&&b[0]<='z')?(b[0]-'a'+1):(b[0]-'A'+27);
        G[u].push_back(edge(v,l));
        G[v].push_back(edge(u,l));
    }
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
    for(i=27;i<=51;i++)
    {
        if(D[i] != MAXINT&&D[i]<min) {min=D[i];id=i;}
    }
    printf("%c %d",id+'A'-27,min);

    return 0;
}
