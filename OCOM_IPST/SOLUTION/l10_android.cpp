#include <stdio.h>
#include <set>
using namespace std;

struct dt
{
    int p,t;
    bool operator < (const dt& T) const
    {
        return t<T.t;
    }
    dt(int _p,int _t)
    {
        p=_p;
        t=_t;
    }
};
set<dt> ST;
set<dt>::iterator pt;
int chk[1010]={0};
int time[1010]={0};
int mem[1010]={0};
int main()
{
    int p,s,m;
    int x;
    scanf("%d%d%d",&p,&s,&m);
    for(int i=1;i<=p;i++) scanf("%d",&mem[i]);
    for(int i=1;i<=s;i++)
    {
        scanf("%d",&x);
        if(chk[x]==1)
        {
            ST.erase(dt(x,time[x]));
            time[x]=i;
            ST.insert(dt(x,time[x]));
            continue;
        }
        while(m<mem[x])
        {
            pt=ST.begin();
            m+=mem[pt->p];
            chk[pt->p]=0;
            ST.erase(dt(pt->p,time[pt->p]));
        }
        chk[x]=1;
        m-=mem[x];
        time[x]=i;
        ST.insert(dt(x,i));
    }
    printf("%d",m);
    return 0;
}
