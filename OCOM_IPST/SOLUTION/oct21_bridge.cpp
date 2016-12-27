#include <stdio.h>
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
using namespace std;

int main()
{
    int n;
    int a[3050]={0};
    int b[3050]={0};
    int c[2][3050]={0};
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
    {
        int u=i%2,v=(i+1)%2;
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j]) c[u][j]=c[v][j-1]+1;
            else c[u][j]=MAX(c[v][j],c[u][j-1]);
        }
    }
    printf("%d",c[n%2][n]);
    return 0;
}
