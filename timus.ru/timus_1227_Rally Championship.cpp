#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;
int dis[115][115]={0};
int mx[115]={0};
vector<int> G[115];
int n,m,s;

int chk(int u,int p)
{
    int siz=G[u].size();
    if(mx[u]>=s) {printf("YES");exit(0);}
    for(int i=0;i<siz;i++)
    {
        int v=G[u][i];
        if(v==p) continue;
        if(mx[v]!=0) {printf("YES");exit(0);}
        mx[v]=mx[u]+dis[u][v];
        chk(v,u);
    }
    return 0;
}
int main()
{
    int a,b,c;
    bool multi=false;
    scanf("%d%d%d",&m,&n,&s);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(dis[a][b]!=0||a==b) multi=true;
        dis[a][b]=c;
        dis[b][a]=c;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(n>=m||multi==true) printf("YES");
    else
    {
        for(int i=1;i<=m;i++)
        {
            //if(G[i].size()==1) bug
            //{
                for(int j=1;j<=m;j++) mx[j]=0;
                chk(i,0);
            //}
        }
        printf("NO");
    }
    return 0;
}
