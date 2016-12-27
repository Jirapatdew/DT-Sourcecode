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
    int u,v;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
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
        printf("%d\n",ans.top());
        ans.pop();
    }
    return 0;
}
