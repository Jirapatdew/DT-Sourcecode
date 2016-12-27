#include <stdio.h>

using namespace std;

int main()
{
    long long n,m,a;
    long long sum=0;
    scanf("%lld%lld%lld",&n,&m,&a);
    sum=(((n+a-1)/a)*((m+a-1)/a));
    printf("%lld",sum);
    return 0;
}