#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;
struct dt
{
    double a;
    int b;
    int name;
    bool operator < (const dt &T) const
    {
        if(a != T.a)return a < T.a;
        else {
            return b > T.b;
        }
    }
    dt(double w,int e,int r)
    {
        a=w;
        b=e;
        name=r;
    }
};
int main()
{
    int T,i,k,t,n,m;
    double v,x;
    set<dt> data[11];// c++ can use dt but c must use struct dt
    set<dt>::iterator pt;
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lf%d",&v,&t);
            x=m/v*1000;
            data[k].insert(dt(x+t,t,i+1));
        }
        pt=data[k].begin();
        while(pt!=data[k].end())
        {
            printf("%d\n",pt->name);
            pt++;
        }
    }
    return 0;
}
