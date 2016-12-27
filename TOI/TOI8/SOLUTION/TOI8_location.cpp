#include <stdio.h>
#define MAX(a,b) (a>b)?a:b

using namespace std;

int a[1005][1005]={0};
int main()
{
    int n,m;
    int k,mx=0;
    scanf("%d%d",&n,&m);
    scanf("%d",&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j]+=a[i][j-1];
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++) a[i][j]+=a[i-1][j];
    for(int i=k;i<=n;i++)
    {
        for(int j=k;j<=m;j++)
        {
            int num=a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k];
            mx=MAX(mx,num);
        }
    }
    printf("%d",mx);
    return 0;
}
