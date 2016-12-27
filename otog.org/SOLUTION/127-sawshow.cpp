#include <stdio.h>
#include <set>

using namespace std;

struct dt
{
    int val;
    int idx;
    bool operator < (const dt &T) const
    {
        if(val!=T.val) return val>T.val;
        else return idx>T.idx;
    }
    dt(int a,int b)
    {
        val=a;
        idx=b;
    }
};
set<dt> Heap;
int chk[1000050];
int main()
{
    int n,m;
    int a,b,c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        chk[i]=a;
        Heap.insert(dt(a,i));
    }
    for(int t=1;t<=m;t++)
    {
        scanf("%d",&c);
        if(c==1)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(chk[a]<=t||chk[b]<=t) continue;
            Heap.erase(dt(chk[a],a));
            Heap.erase(dt(chk[b],b));

            if(chk[b]-t<=c)
            {
                chk[a]+=chk[b]-t;
                chk[b]=0;
                Heap.insert(dt(chk[a],a));
            }
            else
            {
                chk[a]+=c;
                chk[b]-=c;
                Heap.insert(dt(chk[a],a));
                Heap.insert(dt(chk[b],b));
            }
        }
        else if(c==2)
        {
            scanf("%d%d",&a,&b);
            if(chk[a]<=t) continue;
            Heap.erase(dt(chk[a],a));
            chk[a]+=b;
            Heap.insert(dt(chk[a],a));
        }
        else
        {
            if(Heap.empty()||(Heap.begin()->val<=t)) {printf("-1\n");}
            else printf("%d %d\n",Heap.begin()->idx,Heap.begin()->val-t);
        }
    }
    return 0;
}
