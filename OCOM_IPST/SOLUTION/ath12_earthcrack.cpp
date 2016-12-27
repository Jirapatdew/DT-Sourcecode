#include <stdio.h>
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
using namespace std;

int a[2][510]={0};
int main()
{
    int T,n,m,mn=-1u/2;
    scanf("%d",&T);
    while(T>0)
    {
        scanf("%d%d",&n,&m);
        a[0][0]=a[1][0]=a[0][m+1]=a[1][m+1]=-1u/2;
        for(int j=1;j<=m;j++) a[0][j]=a[1][j]=0;
        for(int i=1;i<=n;i++)
        {
            int u=i%2,v=(i+1)%2;
            for(int j=1;j<=m;j++) scanf("%d",&a[u][j]);
            for(int j=1;j<=m;j++) a[u][j]+=MIN(a[v][j],MIN(a[v][j-1],a[v][j+1]));
        }
        mn=-1u/2;
        for(int j=1;j<=m;j++) mn=MIN(mn,a[n%2][j]);
        printf("%d\n",mn);
        T--;
    }
    return 0;
}
