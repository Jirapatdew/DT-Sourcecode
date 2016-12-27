#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> G[100005];
queue<int> Q;
int val[100005]={0};
int main()
{
    int n,m,u,v,a,b;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        G[v].push_back(u);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&a);
        val[u]+=a;
    }
    Q.push(1);
    while(!Q.empty())
    {
        u=Q.front();Q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            v=G[u][i];
            val[v]+=val[u];
            Q.push(v);
        }
    }
    for(int i=1;i<=n;i++) printf("%d\n",val[i]);
    return 0;
}
/*
10 10
2 6
3 2
4 2
5 1
6 5
7 6
8 7
9 3
10 1
9 9
1 1
9 6
1 2
9 8
1 2
4 7
2 9
6 7
2 4
*/
