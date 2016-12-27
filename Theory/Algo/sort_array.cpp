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
bool inMST[MAX_NODE];

int MST(){
    for(int i=0;i<=n;i++) {
        d[i]=INF;
        inMST[i]=false;
    }

    d[1] = 0;
    PQ.push(make_pair(0,1));
    while(!PQ.empty()){
        int u = PQ.top().second;
        int d_u = PQ.top().first;
        PQ.pop();
        if(inMST[u]) continue;
        else inMST[u]=true;

        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!inMST[v] && W[u][i]<d[v]){
                d[v] = W[u][i];
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
        G[y].push_back(x);
        W[x].push_back(w);
        W[y].push_back(w);
    }
    MST();
    for(int i=2;i<=n;i++) printf("%d %d\n",i-1,p[i]-1);

    return 0;
}
/*
9 14
1 2 4
2 3 8
3 4 7
4 5 9
5 6 10
6 7 2
7 8 1
8 1 8
2 8 11
8 9 7
3 9 2
9 7 6
3 6 4
4 6 14
*/
