#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_NODE 100
#define INF 1000000007

vector<int> G[MAX_NODE],W[MAX_NODE];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ; // pair < d , v >
int d[MAX_NODE]={0},p[MAX_NODE]={0},n,e;

int dijkstra(int s){
    for(int i=0;i<=n;i++) d[i]=INF;

    d[s] = 0;
    PQ.push(make_pair(0,s));
    while(!PQ.empty()){
        int u = PQ.top().second;
        PQ.pop();

        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(d[u]+W[u][i]<d[v]){ //W[u][i] = weight u -> v
                d[v] = d[u]+W[u][i];
                PQ.push(make_pair(d[v],v));
                p[v] = u;
            }
        }
    }
}
int main()
{
    int x,y,w;
    scanf("%d%d",&n,&e); // 1 to n
    for(int i=0;i<e;i++) {
        scanf("%d%d%d",&x,&y,&w);
        G[x].push_back(y);
        W[x].push_back(w);
    }
    dijkstra(1);
    for(int i=1;i<=n;i++) printf("%d\n",d[i]);
    return 0;
}
/*
Testcase from somchaiSPJ
7 12
1 2 8
1 3 5
2 5 18
3 2 10
3 4 3
3 6 16
4 2 2
4 5 12
4 7 14
5 7 4
6 4 30
6 7 26
*/
