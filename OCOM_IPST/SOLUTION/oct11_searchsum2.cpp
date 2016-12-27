#include <stdio.h>
#include <algorithm>
#define Min(_x,_y) ((_x)<(_y))?(_x):(_y);
using namespace std;

int main()
{
    int n,k,m;
    int a[100010]={0};
    int b[1010];
    int* pt;
    int mx=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);a[i]+=a[i-1];}
    for(int i=1;i<=n;i++)
    {
        b[i]=-1u/2;
        for(int j=i;j<=n;j++)
        {
            b[i]=min(b[i],a[j]-a[j-i]);
        }
    }

    for(int i=1;i<=k;i++)
    {
        scanf("%d",&m);
        pt=lower_bound(b,b+n+1,m);
        if(pt==b+n+1||*pt!=m) pt--;
        printf("%d\n",pt-b);
    }
    return 0;
}
