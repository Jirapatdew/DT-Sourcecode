#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

map<int,int> G[110];
int chk[110]={0};
int m,n,s;
int dfs(int u,int p,int sum)
{
    chk[u]=1;
    if(sum>=s) {printf("YES");exit(0);}
    for(map<int,int>::iterator pt=G[u].begin();pt!=G[u].end();pt++)
    {
        int v=pt->first;
        int val=pt->second;
        if(v==p) continue;
        if(chk[v]==1) {printf("YES");exit(0);}
        dfs(v,u,sum+val);
    }
    return 0;
}
int main()
{
    int a,b,v;
    bool multi=false;

    map<int,int>::iterator pt;
    scanf("%d%d%d",&m,&n,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a,&b,&v);
        if(a==b) {multi=true;continue;}
        pt=G[a].find(b);
        if(pt==G[a].end())
        {
            G[a][b]=v;
            G[b][a]=v;
        }
        else multi=true;
    }
    if(n>=m||multi) {printf("YES");return 0;}
    else
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++) chk[j]=0;
            dfs(i,0,0);
        }
    }
    printf("NO");
    return 0;
}
