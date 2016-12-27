#include <stdio.h>
#include <set>

using namespace std;

int a[500050]={0};
int f[500050]={0};
multiset<int> DT;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    f[1]=a[1];
    for(int i=2;i<=k+1;i++)
    {
        f[i]=f[1]+a[i];
        DT.insert(f[i]);
    }
    for(int i=k+2;i<=n;i++)
    {
        multiset<int>::iterator pt=DT.begin();
        f[i]=a[i]+(*pt);
        pt=DT.lower_bound(f[i-k]);
        DT.erase(pt);
        DT.insert(f[i]);
    }
    printf("%d",f[n]);
    return 0;
}
