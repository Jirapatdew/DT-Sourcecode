#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,m;
    int a[100010]={0};
    int* pt;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);a[i]+=a[i-1];}
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&m);
        pt=lower_bound(a+1,a+n+1,m);
        if(pt==a+n+1||*pt!=m) pt--;
        printf("%d\n",pt-a);
    }
    return 0;
}
