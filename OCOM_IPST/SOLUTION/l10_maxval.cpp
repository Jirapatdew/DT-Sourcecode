#include <stdio.h>
#define MAX(_x,_y) ((_x)>(_y))?(_x):(_y)
using namespace std;

int a[1000010]={0};
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]);a[i]+=a[i-1];}
    int mx=a[k];
    for(int i=k+1;i<=n;i++) mx=MAX(mx,a[i]-a[i-k]);
    printf("%d",mx);
    return 0;
}
