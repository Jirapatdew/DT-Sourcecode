#include <stdio.h>
#include <vector>
#include <set>
#define MIN(a,b) ((a)<0?-(a):a)
//#define ab(a) ((a<0)?-a:a)
#define INF 1000000000
using namespace std;

char data[10050];

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
struct dt
{
    int x;
    int y;
};
int ab(int a)
{
    if(a<0) return -a;
    else return a;
}
set<heap> C;
vector<dt> ver;
int D[10000];
int main()
{
    int n,m,k;
    dt tmp;
    int A,B;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&data[1]);
        tmp.x=i;
        for(int j=1;j<=m;j++)
        {
            tmp.y=j;
            if(data[j]!='.') ver.push_back(tmp);
            if(data[j]=='A') A=ver.size()-1;
            if(data[j]=='B') B=ver.size()-1;
        }
    }
    for(int i=0;i<=ver.size();i++) D[i]=INF;
    D[A]=0;
    C.insert(heap(0,A));
    while(!C.empty())
    {
        int u=C.begin()->idx;
        for(int i=0;i<=ver.size();i++)
        {
            int v=i;
            int w=ab(ver[u].x-ver[v].x)+ab(ver[u].y-ver[v].y);
            if(u==v||w>k) continue;
            if(D[v]>D[u]+w)
            {
                C.erase(heap(D[v],v));
                C.insert(heap(D[u]+w,v));
                D[v]=D[u]+w;
            }
        }
        C.erase(C.begin());
    }
    if(D[B]==INF) printf("-1");
    else printf("%d",D[B]);
    return 0;
}
