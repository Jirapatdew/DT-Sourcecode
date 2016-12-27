#include <stdio.h>
#include <algorithm>
using namespace std;

int a[300050]={0};
int ab(int c)
{
    return (c<0)?-c:c;
}
int main()
{
    int  n;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++)
        sum+=ab(a[i]-(i+1));
    printf("%lld",sum);
    return 0;
}