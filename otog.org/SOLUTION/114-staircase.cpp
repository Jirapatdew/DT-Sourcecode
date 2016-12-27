#include <stdio.h>
#define MIN(a,b) (a<b)?a:b

using namespace std;

long long f[505][505]={0};
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) f[i][i]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            a=MIN(i-j,j-1);
            f[i][j]+=f[i-j][a];
        }
        for(int j=1;j<=i;j++) f[i][j]+=f[i][j-1];
    }
    printf("%lld",f[n][n]-1);
    return 0;
}
