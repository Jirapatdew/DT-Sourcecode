#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
using namespace std;


int w[100010]={0};
int val[100010][2]={0};
int chk[100010]={0};
vector<int> G[100010];
queue<int> Q;
stack<int> S;
int BFS()
{
    int u,v;
    Q.push(0);
    chk[0]=1;
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        S.push(u);
        int sz=G[u].size();
        for(int i=0;i<sz;i++)
        {
            if(chk[G[u][i]]==0) {Q.push(G[u][i]);chk[G[u][i]]=1;}
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&w[i]);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0;i<n;i++) val[i][0]=w[i];
    BFS();
    while(!S.empty())
    {
        int u=S.top(),v=-1;
        S.pop();
        chk[u]=0;
        int sz=G[u].size();
        for(int i=0;i<sz;i++)
        {
            if(chk[G[u][i]]==1) v=G[u][i];
        }
        if(v==-1) break;
        val[v][0]+=val[u][1];
        val[v][1]+=MAX(val[u][0],val[u][1]);
    }
    int mx=0;
    for(int i=0;i<n;i++) mx=MAX(mx,val[i][0]);
    for(int i=0;i<n;i++) mx=MAX(mx,val[i][1]);
    printf("%d",mx);
    return 0;
}
//#include <stdio.h>
//#include <vector>
//#include <queue>
//#define MAX(_x,_y) (((_x)>(_y))?(_x):(_y))
//using namespace std;
//
//
//int w[100010]={0};
//int val[100010][2]={0};
//int chk[100010]={0};
//vector<int> G[100010];
//queue<int> Q;
//int BFS()
//{
//    int u,v;
//    while(!Q.empty())
//    {
//        u=Q.front();
//        Q.pop();
//        chk[u]=2;
//        v=-1;
//        int sz=G[u].size();
//        for(int i=0;i<sz;i++)
//        {
//            if(chk[G[u][i]]==0) {Q.push(G[u][i]);chk[G[u][i]]=1;}
//            if(chk[G[u][i]]!=2) {v=G[u][i];break;}
//        }
//        if(v==-1) break;
//        val[v][0]+=val[u][1];
//        val[v][1]+=MAX(val[u][0],val[u][1]);
//    }
//}
//int main()
//{
//    int n;
//    scanf("%d",&n);
//    for(int i=0;i<n;i++) scanf("%d",&w[i]);
//    for(int i=0;i<n-1;i++)
//    {
//        int u,v;
//        scanf("%d%d",&u,&v);
//        G[u].push_back(v);
//        G[v].push_back(u);
//    }
//    for(int i=0;i<n;i++)
//    {
//        val[i][0]=w[i];
//        if(G[i].size()==1)
//        {
//            Q.push(i);
//            chk[i]=1;
//        }
//    }
//    BFS();
//
//    int mx=0;
//    for(int i=0;i<n;i++) mx=MAX(mx,val[i][0]);
//    for(int i=0;i<n;i++) mx=MAX(mx,val[i][1]);
//    printf("%d",mx);
//    return 0;
//}
