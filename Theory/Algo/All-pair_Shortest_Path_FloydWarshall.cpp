#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_NODE 100
#define INF 1000000007

int D[MAX_NODE][MAX_NODE]={0};
int n,e;

int FloydWarshall(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
}
int main()
{
    int x,y,w;
    scanf("%d%d",&n,&e); // 1 to n
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) D[i][j] = INF;
            else D[i][j] = 0;
    for(int i=0;i<e;i++) {
        scanf("%d%d%d",&x,&y,&w);
        D[x][y]=w;
    }
    FloydWarshall();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
Testcase from somchaiSPJ
7 12
1 2 8
1 3 5
2 5 18
3 2 10
3 4 3
3 6 16
4 2 2
4 5 12
4 7 14
5 7 4
6 4 30
6 7 26
*/
