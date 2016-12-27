#include <stdio.h>
#include <stdlib.h>

long long lcm=0;
long long gcd(long long a,long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int n,i;
    long long data[50001];
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%lld",&data[i]);
    lcm=(data[0]*data[1])/gcd(data[0],data[1]);
    for(i=2;i<n;i++)
    {
        lcm=(data[i]*lcm)/gcd(data[i],lcm);
    }
    printf("%lld",lcm);
    return 0;
}
