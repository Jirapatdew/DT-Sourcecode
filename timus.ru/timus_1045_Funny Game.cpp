#include <cstdio>
#include <set>

using namespace std;

set<int> G[1005];
int idx;
int dfs(int v,int p,int num)
{
    int win=-1;
    set<int>::iterator pt;
    for(pt=G[v].begin();pt!=G[v].end();pt++)
    {
        if(*pt==p) continue;
        win=dfs(*pt,v,num+1);
        if(win!=(num%2)) {idx=*pt;return win;}
    }
    return num%2;
}
int main()
{
    int n,k;
    int a,b,win;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].insert(b);
        G[b].insert(a);
    }
    win=dfs(k,-1,1);
    if(win==0) printf("First player wins flying to airport %d",idx);
    else printf("First player loses");
}
