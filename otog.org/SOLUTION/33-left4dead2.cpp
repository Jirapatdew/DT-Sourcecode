#include <stdio.h>
#define MIN(a,b) (a<b)?a:b
#define INF 2000000000
using namespace std;

int a[100050]={0};
int main()
{
    long long n,m,mn=INF;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) {scanf("%lld",&a[i]);mn=MIN(mn,a[i]);}
    long long lo=0,hi=m*mn;
    while(lo<hi)
    {
        long long mid=(lo+hi)/2,num=0;
        for(int i=1;i<=n;i++) num+=mid/a[i];
        if(num<m) lo=mid+1;
        else hi=mid;
    }
    printf("%lld",lo);
    return 0;
}
