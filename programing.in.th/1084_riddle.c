#include <stdio.h>
#include <stdlib.h>
// testcase 15 27 100 => 53
int main()
{
    long long x,y,k,i,j;
    long long num=0,a,b,total;
    scanf("%lld%lld%lld",&x,&y,&k);

    b=1;
    while(1)
    {
        b*=5;
        a=x/b;
        if(a==0) break;
        else num+=a;
    }
    total=(num%k)*((y-x+1)%k);
    total%=k;

    b=1;
    for(i=1;i<=12;i++)
    {
        b*=5;
        if(b>y) break;
        a=x+b-(x%b);
        for(j=a;j<=y;j+=b)
        {
            total+=y-j+1;
            total%=k;
        }
    }
    printf("%lld",total%k);
    return 0;
}
