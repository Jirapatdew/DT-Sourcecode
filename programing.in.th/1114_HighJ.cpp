#include <stdio.h>
#define MIN(a,b) (a<b)?a:b
#define INF 1000000000

using namespace std;

int w[650][650]={0};
int f[650]={0};

int main()
{
    int n;
    scanf("%d",&n);
    n*=2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&w[i][j]);
    for(int i=3;i<=n;i++)
    {
        f[i]=INF;
        for(int j=2;j<i;j++)
        {
            f[i]=MIN(f[i],f[j]+w[i][j]);
        }
    }
    printf("%d",f[n]);
    return 0;
}
