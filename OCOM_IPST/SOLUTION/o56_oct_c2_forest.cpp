#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
#define INF (-1u/4)

using namespace std;

int M[100][100]={0};//1...n
int P[100][4]={0};//1...n
int dm[100][100][100]={0};//1...n
int main()
{
    int n,p,K;
    scanf("%d%d%d",&n,&p,&K);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&M[i][j]);
    for(int i=1;i<=p;i++)
        for(int j=0;j<4;j++) {scanf("%d",&P[i][j]);P[i][j]++;}
    for(int k=0;k<=K;k++)
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=n+1;j++) dm[k][i][j]=INF;
    dm[0][1][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dm[0][i][j]=MIN(dm[0][i-1][j],dm[0][i][j-1])+M[i][j];

//        printf("\n");
//        for(int i=1;i<=n;i++)
//            {for(int j=1;j<=n;j++) printf("%d ",dm[0][i][j]);printf("\n");}

    for(int k=1;k<=K;k++)
    {
        for(int i=1;i<=p;i++)
            if(dm[k-1][P[i][0]][P[i][1]]!=INF)
            {
                dm[k][P[i][2]][P[i][3]]=MIN(dm[k][P[i][2]][P[i][3]],dm[k-1][P[i][0]][P[i][1]]);
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dm[k][i-1][j]!=INF||dm[k][i][j-1]!=INF)
                {
                    int tmp=MIN(dm[k][i-1][j],dm[k][i][j-1])+M[i][j];
                    dm[k][i][j]=MIN(dm[k][i][j],tmp);
                }
        for(int i=n;i>0;i--)
            for(int j=n;j>0;j--)
                if(dm[k][i+1][j]!=INF||dm[k][i][j+1]!=INF)
                {
                    int tmp=MIN(dm[k][i+1][j],dm[k][i][j+1])+M[i][j];
                    dm[k][i][j]=MIN(dm[k][i][j],tmp);
                }
//        printf("\n");
//        for(int i=1;i<=n;i++)
//            {for(int j=1;j<=n;j++) printf("%d ",dm[k][i][j]);printf("\n");}
    }
    int mn=INF;
    for(int k=0;k<=K;k++)
    {
        mn=MIN(mn,dm[k][n][n]);
    }
    printf("%d",mn);
    return 0;
}
