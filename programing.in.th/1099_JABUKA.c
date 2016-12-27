#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long R,G,n,i,j;
    scanf("%lld%lld",&R,&G);
    if(R>G) n=sqrtl(G);
    else n=sqrtl(R);
    for(i=1;i<=n;i++)
    {
        if(R%i==0&&G%i==0) printf("%lld %lld %lld\n",i,R/i,G/i);
    }
    for(i=n;i>=1;i--)
    {
        if(R>G) j=G/i;
        else j=R/i;
        if((i*i!=R||i*i!=G)&&R%j==0&&G%j==0) printf("%lld %lld %lld\n",j,R/j,G/j);
    }
    return 0;
}
//(i*i!=R||i*i!=G) ถ้าไม่มีจะผิดกรณี 12 12 จะไม่ print 4 3 3
