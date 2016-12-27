#include <stdio.h>
#include <set>
#include <queue>
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
using namespace std;

struct dt
{
    int m,a,b,val;
    bool operator < (const dt& T) const
    {
        if(m!=T.m) return m<T.m;
        else if(a!=T.a) return a<T.a;
        else return b<T.b;
    }
};
set<dt> ST;
set<dt>::iterator pt;
queue<dt> Q;
int main()
{
    int m,K;
    int A,B,T;
    dt u;
    scanf("%d%d",&m,&K);
    u.a=u.b=u.m=u.val=0;
    ST.insert(u);
    for(int k=1;k<=K;k++)
    {
        scanf("%d%d%d",&A,&B,&T);
        for(pt=ST.begin();pt!=ST.end();pt++)
        {
            Q.push(*pt);
        }
        while(!Q.empty())
        {
            u=Q.front();
            Q.pop();
            if(u.m+A<=m)
            {
                if(T==0) u.a++;
                else u.b++;
                u.m+=A;
                u.val+=B;
                pt=ST.find(u);
                if(pt==ST.end()) ST.insert(u);
                else if(pt->val<u.val)
                {
                    ST.erase(pt);
                    ST.insert(u);
                }
            }
        }
    }
    int mx=0;
    for(pt=ST.begin();pt!=ST.end();pt++)
    {
        u=*pt;
        if((MAX(u.a,u.b)-1)/2>MIN(u.a,u.b)) continue;
        mx=MAX(mx,u.val);
    }
    printf("%d",mx);
    return 0;
}
