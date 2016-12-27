#include <stdio.h>
#include <list>
using namespace std;

list<int> G[100010];
int chk[100010]={0};
int DFS(int u,int num)
{
    chk[u]=num;
    list<int>::iterator pt;
    for(pt=G[u].begin();pt!=G[u].end();pt++)
    {
        int v=*pt;
        if(chk[v]==0) {if(!DFS(v,num+1)) return false;}
        else if(chk[v]%2!=chk[u]%2) continue;
        else return false;
    }
    return true;
}
int main()
{
    int n,k,m,p=0;
    scanf("%d",&k);
    while(k>0)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) {G[i].clear();chk[i]=0;}
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        p=0;
        for(int i=1;i<=n;i++) if(chk[i]==0) {if(!DFS(i,1)) {printf("no\n");p=1;break;}}
        if(p==0) printf("yes\n");
        k--;
    }

    return 0;
}
