#include <stdio.h>
#define INF 1000000000

using namespace std;

int a[1010]={0},b[1010]={0};
int M,N;
struct dt
{
    int d;
    int m;
}f[1010][1010];
dt MIN(int i,int j)
{
    dt tmp1={INF,0},tmp2={INF,0};
    if(i==0&&j==0) {tmp1.d=0;return tmp1;}
    if(i!=0)
    {
        tmp1.d=f[i-1][j].d;
        if(f[i-1][j].m+b[i]>M)
        {
            tmp1.d++;
            tmp1.m=b[i];
        }
        else tmp1.m=f[i-1][j].m+b[i];
    }
    if(j!=0)
    {
        tmp2.d=f[i][j-1].d;
        if(f[i][j-1].m+a[j]>M)
        {
            tmp2.d++;
            tmp2.m=a[j];
        }
        else tmp2.m=f[i][j-1].m+a[j];
    }
    if(tmp1.d<tmp2.d) return tmp1;
    if(tmp2.d<tmp1.d) return tmp2;
    if(tmp1.d==tmp2.d)
    {
        if(tmp1.m<tmp2.m) return tmp1;
        else return tmp2;
    }
}
int main()
{
    scanf("%d%d",&M,&N);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    for(int i=1;i<=N;i++) scanf("%d",&b[i]);
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            f[i][j]=MIN(i,j);
        }
    }
    printf("%d\n%d",f[N][N].d+1,f[N][N].m);
    return 0;
}
