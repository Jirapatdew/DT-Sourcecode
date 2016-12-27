#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

vector<int> G[100010];
stack<int> ans;
int chk[100010]={0};
bool tsort(int u)
{
    int v;
    chk[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        v=G[u][i];
        if(chk[v]==0)
        {
            if(!tsort(v)) return false;
        }
        else if(chk[v]==1) return false;
    }
    ans.push(u);
    chk[u]=2;
    return true;
}
int main()
{
    int n,m;
    int a,b,c;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back(b);
        G[b].push_back(c);
    }
    for(int i=1;i<=n;i++)
    {
        if(chk[i]==0)
        {
            if(!tsort(i)) {printf("no");return 0;}
        }
    }
    while(!ans.empty())
    {
        printf("%d ",ans.top());
        ans.pop();
    }
    return 0;
}
