#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

map<int,int> G[105];
int col[105];
bool bipa=false;
int dfs(int u,int p)
{
    for(map<int,int>::iterator pt=G[u].begin();pt!=G[u].end();pt++)
    {
        int v=pt->first;
        if(v==p) continue;
        if(col[v]==2)
        {
            col[v]=(col[u]+1)%2;
            dfs(v,u);
        }
        else if(col[v]!=(col[u]+1)%2) {printf("-1");exit(0);}
    }
    return 0;
}
int main()
{
    int n;
    int a;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        while(a!=0)
        {
            G[i][a]=0;
            G[a][i]=0;
            scanf("%d",&a);
        }
    }
    for(int i=1;i<=n;i++) col[i]=2;
    for(int i=1;i<=n;i++)
    {
        if(col[i]==2) {col[i]=0;dfs(i,0);}
    }
    for(int i=1;i<=n;i++) printf("%d",col[i]);
    return 0;
}
