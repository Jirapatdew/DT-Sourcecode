#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
#define INF (-1u/4)

using namespace std;

int mem[30][30]={0};
int M[30][30]={0};
int chk_M[30][30]={0};
int a[30][5]={0};
int N,P,K;
int def(int x,int y,int use,int val)
{
    if(use>K) return 0;
    if(x<1||x>N||y<1||y>N) return 0;
    int sum=val+M[x][y];
    if(sum<mem[x][y])
    {
        mem[x][y]=sum;
        def(x+1,y,use,sum);
        def(x-1,y,use,sum);
        def(x,y+1,use,sum);
        def(x,y-1,use,sum);
        if(chk_M[x][y]!=0) def(a[chk_M[x][y]][2],a[chk_M[x][y]][3],use+1,sum-M[a[chk_M[x][y]][2]][a[chk_M[x][y]][3]]);
    }

}
int main()
{

    scanf("%d%d%d",&N,&P,&K);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++) scanf("%d",&M[i][j]);
    for(int i=1;i<=P;i++)
    {
        for(int j=0;j<4;j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]++;
            }
        chk_M[a[i][0]][a[i][1]]=i;
    }
    for(int i=0;i<30;i++)
        for(int j=0;j<30;j++)  mem[i][j]=INF;
    M[1][1]=0;
    def(1,1,0,0);
    printf("%d",mem[N][N]);
    return 0;
}
