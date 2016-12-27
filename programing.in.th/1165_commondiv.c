#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int data[15]={0};
long long int gcd(long long int a,long long int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    long long int a,all_gcd,rt;
    long long int n,i,num=0;
    scanf("%lld",&n);
    scanf("%lld",&all_gcd);
    for(i=1;i<n;i++)
    {
        scanf("%lld",&a);
        all_gcd=gcd(a,all_gcd);
    }
    rt=sqrtl(all_gcd);
    for(i=1;i<rt;i++)
        if(all_gcd%i==0) num+=2;
    if(all_gcd%rt==0) num++;
    printf("%lld",num);
    return 0;
}
