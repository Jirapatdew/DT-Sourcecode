#include <stdio.h>
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
using namespace std;

int a[1010]={0};
int f[1010]={0};
int p[1010]={0};
int print(int u)
{
    if(u==0) return 0;
    print(p[u]);
    printf("%d ",a[u]);
}
int main()
{
    int n,mx=0,id;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[i]>a[j]&&f[i]<f[j]+1)
            {
                f[i]=f[j]+1;
                p[i]=j;
            }
        }
        if(mx<f[i])
        {
            mx=f[i];
            id=i;
        }
    }
    printf("%d\n",mx);
    print(id);
    return 0;
}
