#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MIN(_x,_y) (((_x)<(_y))?(_x):(_y))
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
#define INF (-1u/4)

using namespace std;

int M[100][100]={0};//1...n
int P[100][4]={0};//1...n
int dm[100][100]={0};//1...n
int main()
{
    int n,p,K;
    scanf("%d%d%d",&n,&p,&K);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) scanf("%d",&M[i][j]);
    for(int i=1;i<=p;i++)
        for(int j=0;j<4;j++) {scanf("%d",&P[i][j]);P[i][j]++;}
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=n+1;j++) dm[i][j]=INF;
    dm[0][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dm[i][j]=MIN(dm[i-1][j],dm[i][j-1])+M[i][j];

    for(int k=1;k<=K;k++)
    {
//        printf("\n");
//        for(int i=1;i<=n;i++)
//            {for(int j=1;j<=n;j++) printf("%d ",dm[i][j]);printf("\n");}
        for(int i=1;i<=p;i++)
            if(dm[P[i][0]][P[i][1]]<dm[P[i][2]][P[i][3]])
            {
                dm[P[i][2]][P[i][3]]=dm[P[i][0]][P[i][1]];
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                    dm[i][j]=MIN(dm[i][j],dm[i][j-1]+M[i][j]);
                    dm[i][j]=MIN(dm[i][j],dm[i-1][j]+M[i][j]);
                }
        for(int i=n;i>0;i--)
            for(int j=n;j>0;j--)
                {
                    dm[i][j]=MIN(dm[i][j],dm[i][j+1]+M[i][j]);
                    dm[i][j]=MIN(dm[i][j],dm[i+1][j]+M[i][j]);
                }
    }
//    printf("\n");
//        for(int i=1;i<=n;i++)
//            {for(int j=1;j<=n;j++) printf("%d ",dm[i][j]);printf("\n");}
    printf("%d",dm[n][n]);
    return 0;
}
