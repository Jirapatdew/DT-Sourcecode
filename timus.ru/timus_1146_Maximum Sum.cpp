#include <stdio.h>
#define MAX(a,b) (a>b)?a:b
#define INF 2000000050
using namespace std;

int main()
{
    int data[105][105]={0},n,mx=-INF;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&data[i][j]);
    for(int j=1;j<=n;j++)
        for(int i=1;i<=n;i++) data[i][j]+=data[i-1][j];
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            int sum=0;
            for(int k=1;k<=n;k++)
            {
                sum=MAX(sum+data[j][k]-data[i-1][k],data[j][k]-data[i-1][k]);
                if(mx<sum) mx=sum;
            }
        }
    printf("%d",mx);
    return 0;
}
