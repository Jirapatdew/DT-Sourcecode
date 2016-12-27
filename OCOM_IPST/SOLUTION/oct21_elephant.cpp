#include <stdio.h>
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
using namespace std;

int main()
{
    int n;
    int a[100010]={0};
    int f[100010]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);

    for(int i=3;i<=n;i++)
    {
        f[i]=MAX(f[i-1],f[i-3]+a[i]);
    }
    printf("%d",f[n]);
    return 0;
}
