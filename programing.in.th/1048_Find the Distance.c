#include <stdio.h>
#include <stdlib.h>


int main()
{
    int k;
    int i;
    long long dif=0,d=1,n,x;
    scanf("%d%lld",&k,&n);
    for(i=0;i<k;i++)
    {
        x=n/d;
        dif+=x;
        d*=2;
    }
    printf("%lld",dif);
    return 0;
}
