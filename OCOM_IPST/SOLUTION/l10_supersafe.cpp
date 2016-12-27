#include <stdio.h>

using namespace std;

int main()
{
    long long n,t,v,s;
    long long pt,pv;
    scanf("%lld%lld",&n,&s);
    scanf("%lld%lld",&pt,&pv);
    printf("0\n");
    for(int i=1;i<n;i++)
    {
        scanf("%lld%lld",&t,&v);
        long long ds=s-((t-pt)*pv);
        if(ds<0||v<pv) {printf("0\n");pv=v;}
        else
        {
            long long dv=s*pv/ds;
            if(dv<v) {printf("%lld\n",v-dv);pv=dv;}
            else {printf("0\n");pv=v;}
        }
        pt=t;
    }
    return 0;
}
