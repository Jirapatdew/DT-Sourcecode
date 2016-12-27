#include <stdio.h>
#define MAX(a,b) (a>b)?a:b
#define INF 2000000000
using namespace std;

int a[5050]={0};
int f[5050]={0};
int main()
{
    int n,m;
    double t;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%lf",&a[i],&t);
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]<=a[i]) f[i]=MAX(f[i],f[j]+1);
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++) mx=MAX(f[i],mx);
    printf("%d",n-mx);
    return 0;
}
