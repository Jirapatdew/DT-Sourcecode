#include <stdio.h>
#define MAX(_x,_y) ((_x)>(_y))?(_x):(_y);
using namespace std;


int main()
{
    int n;
    int a[110]={0};
    int f[110][110]={0};
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
    for(int k=2*n;k>=1;k--)
    {
        for(int i=k,j=2*n;i>0;i--,j--)
        {
            if(i+1<=2*n&&j-1>0) f[i][j]=MAX(f[i+1][j-1]+a[i],f[i+1][j-1]+a[j]);
            if(i+2<=2*n) f[i][j]=MAX(f[i][j],f[i+2][j]+a[i]);
            if(j-2>0) f[i][j]=MAX(f[i][j],f[i][j-2]+a[j]);
        }
    }
    printf("%d",f[1][2*n]);
    return 0;
}
