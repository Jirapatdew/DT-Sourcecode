#include <stdio.h>
#include <algorithm>
#define ab(_x) (((_x)<0)?-(_x):(_x))
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
using namespace std;

int num[2][210]={0};
int main()
{
    int c,n,k;
    int a,b;

    scanf("%d%d",&n,&k);

    for(int i=1;i<210;i++) num[0][i]=num[1][i]=-1u/2;
    num[0][100]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        int u=i%2,v=(i+1)%2;
        for(int j=100-k;j<=100+k;j++) num[v][j]=-1u/2;
        for(int j=100-k;j<=100+k;j++)
        {
            if(num[u][j]!=-1u/2)
            {
                if(j-1>=100-k) num[v][j-1]=MIN(num[v][j-1],num[u][j]+a);
                if(j+1<=100+k) num[v][j+1]=MIN(num[v][j+1],num[u][j]+b);
            }
        }
    }
    int mn=-1u/2;
    for(int j=100-k;j<=100+k;j++) mn=MIN(mn,num[n%2][j]);
    printf("%d",mn);


    return 0;
}
