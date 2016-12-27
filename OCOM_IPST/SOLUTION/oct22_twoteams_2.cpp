#include <stdio.h>
#include <list>
using namespace std;

list<int> G[100010];
int chk[100010]={0};
int in[100010][2]={0};
int n,m;
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
int Bi(int left,int right)
{
    int mid=(left+right+1)/2;///***///
    if(left==right) return mid;
    for(int i=1;i<=n;i++) {G[i].clear();chk[i]=0;}
    for(int i=1;i<=mid;i++)
    {
        int u,v;
        u=in[i][0];
        v=in[i][1];
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int p=1;
    for(int i=1;i<=n;i++) if(chk[i]==0) {if(!DFS(i,1)) {p=0;break;}}
    if(p==1) return Bi(mid,right);
    else return Bi(left,mid-1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&in[i][0],&in[i][1]);
    printf("%d",Bi(1,m));
    return 0;
}
