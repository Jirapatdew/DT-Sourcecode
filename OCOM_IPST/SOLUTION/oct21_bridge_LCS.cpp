#include <stdio.h>
#define MAX(a,b) (a>b)?a:b
#define INF 1000000000

using namespace std;

int a[3005]={0};
int b[3005]={0};
int f[3005][3005]={0};
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=MAX(f[i-1][j],f[i][j-1]);
        }
    }
    printf("%d",f[n][n]);
    return 0;
}
