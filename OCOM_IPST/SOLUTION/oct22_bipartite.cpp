#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

vector<int> G[100005];
int p=0;
int DFS(int node,int color)//0=red 1=black
{
    int i,s=G[node].size(),child;
    G[node][0]=color;
    if(p==1) return 0;
    for(i=1;i<s;i++)
    {
        child=G[node][i];
        if(G[child][0]==-1) DFS(child,(color+1)%2);
        else if(G[child][0]==color)
        {
            p=1;
        }
    }
}

int main()
{
    int K;
    int n,m;
    int a,b;
    int i;
    scanf("%d",&K);
    while(K>0)
    {
        scanf("%d%d",&n,&m);
        p=0;
        for(i=1;i<=n;i++) G[i].push_back(-1);//-1 you never visit
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        DFS(1,0);
        if(p==0) printf("yes\n");
        else printf("no\n");
        for(i=1;i<=n;i++) G[i].clear();
        K--;
    }
    return 0;
}
