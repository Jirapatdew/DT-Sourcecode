#include <stdio.h>

using namespace std;

int E[60][60]={0};
int in[6000][2]={0};
int num=1,n,m;
int DFS(int u)
{
    for(int i=1;i<=n;i++)
    {
        if(E[u][i]==-1)
        {
            E[u][i]=num;
            E[i][u]=num;
            num++;
            DFS(i);
        }
    }
    return 0;
}
int main()
{
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&in[i][0],&in[i][1]);
        E[in[i][0]][in[i][1]]=-1;
        E[in[i][1]][in[i][0]]=-1;
    }
    DFS(1);
    printf("YES\n");
    for(int i=1;i<=m;i++) printf("%d ",E[in[i][0]][in[i][1]]);
    return 0;
}
