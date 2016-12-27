#include <stdio.h>
#include <set>
#include <map>
#define INF 1000000000

using namespace std;
struct heap
{
    int v;
    int idx;
    bool operator < (const heap &T) const
    {
        if(v!=T.v) return v<T.v;
        else return idx<T.idx;
    }
    heap(int a,int b)
    {
        v=a;
        idx=b;
    }
};
set<heap> C;
map<int ,int > G[100050];
int D[100050];
int main()
{
    int n,m;
    int start,stop;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,v;
        scanf("%d%d%d",&a,&b,&v);
        G[a][b]=v;
        G[b][a]=v;
    }
    for(int i=1;i<=n;i++) D[i]=INF;
    scanf("%d%d",&start,&stop);
    D[start]=0;
    C.insert(heap(0,start));
    while(!C.empty())
    {
        int u=C.begin()->idx;
        for(map<int,int>::iterator pt=G[u].begin();pt!=G[u].end();pt++)
        {
            int v=pt->first;
            int w=pt->second;
            if(D[v]>D[u]+w)
            {
                C.erase(heap(D[v],v));
                C.insert(heap(D[u]+w,v));
                D[v]=D[u]+w;
            }
        }
        C.erase(C.begin());
    }
    printf("%d",D[stop]);
    return 0;
}
