#include <stdio.h>
#define INF 2000000000
#define MIN(a,b) ((a<b)?a:b)
using namespace std;

int f[1050][1050]={0};
int main()
{
    int n,a,b;
    int x,y;
    scanf("%d%d%d",&n,&a,&b);
    //for(int i=1;i<=n;i++)
    //    for(int j=1;j<=i;j++) f[i][j]=INF;
    //f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        f[i][0]=f[i-1][0]+y;
        for(int j=1;j<i;j++)
        {
            f[i][j]=MIN(f[i-1][j-1]+x,f[i-1][j]+y);
        }
        f[i][i]=f[i-1][i-1]+x;
    }
    int mn=INF,num;
    for(int i=0;i<=n;i++)
    {
        num=i-(n-i);
        if(a<=num&&num<=b) mn=MIN(mn,f[n][i]);
    }
    printf("%d",mn);
    return 0;
}
